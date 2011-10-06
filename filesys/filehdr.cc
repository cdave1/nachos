// filehdr.cc 
//	Routines for managing the disk file header (in UNIX, this
//	would be called the i-node).
//
//	The file header is used to locate where on disk the 
//	file's data is stored.  We implement this as a fixed size
//	table of pointers -- each entry in the table points to the 
//	disk sector containing that portion of the file data
//	(in other words, there are no indirect or doubly indirect 
//	blocks). The table size is chosen so that the file header
//	will be just big enough to fit in one disk sector, 
//
//      Unlike in a real system, we do not keep track of file permissions, 
//	ownership, last modification date, etc., in the file header. 
//
//	A file header can be initialized in two ways:
//	   for a new file, by modifying the in-memory data structure
//	     to point to the newly allocated data blocks
//	   for a file already on disk, by reading the file header from disk
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"

#include "system.h"
#include "filehdr.h"

//----------------------------------------------------------------------
// FileHeader::Allocate
// 	Initialize a fresh file header for a newly created file.
//	Allocate data blocks for the file out of the map of free disk blocks.
//	Return FALSE if there are not enough free blocks to accomodate
//	the new file.
//
//	"freeMap" is the bit map of free disk sectors
//	"fileSize" is the bit map of free disk sectors
//----------------------------------------------------------------------
#ifdef CHANGED


//
void 
FileHeader::Initialise()
{
  numBytes = 0;
  numSectors = 0;
  singleIndirectSector = 0;
  doubleIndirectSector = 0;
}


// Allocates the new bytes to the sectors available to the file header.
//
// These sectors come in a certain order:
// - Direct blocks.
// - A single indirect.
// - A double indirect block.
//
// If it runs out of direct blocks with still more space to allocate, then
// it will attempt to allocate space in the single indirect block.
//
// If the single indirect runs out of space, then a double indirect block
// will be created, and single indirect blocks will be allocated.
bool
FileHeader::Allocate(BitMap *freeMap, int bytes)
{ 
  int newSize = numBytes + bytes;
  int newSectors = divRoundUp(bytes, SectorSize);

  DEBUG('f', "Making room for %d bytes\n", bytes);

  // Check the bitmap to see if there are enough clear sectors.
  if (freeMap->NumClear() < newSectors) {
    DEBUG('f', "### OUT OUT MEMORY ###\n");
    return FALSE;		// not enough space
  }
  

  // Allocate direct block space.
  this->AllocateDirectBlocks(newSize, freeMap);
  if (newSize <= (NumDirect * SectorSize)) return TRUE;

  
  // Need to create the single indirect here
  ASSERT(numBytes >= (NumDirect * SectorSize));
  this->CreateSingleIndirectBlock(newSize, freeMap);
  int allocated = this->AllocateIndirectSpace(newSize, singleIndirectSector, (NumDirect * SectorSize), freeMap);
  if (allocated == 0) return TRUE;


  // Create the double indirect then allocate to it.
  this->AllocateDoubleIndirectBlock(newSize, freeMap);
  return TRUE;
}


// Allocates space within the direct blocks of the inode.
void
FileHeader::AllocateDirectBlocks(int newSize, BitMap* freeMap)
{
  while (numBytes >= 0 && numBytes < (NumDirect * SectorSize)) {
    if (newSize <= (numSectors * SectorSize)) {
	numBytes = newSize;
	break;
    } else {
      numBytes = (numSectors * SectorSize);
	
      if (numSectors < NumDirect) {
	// This action needs to be atomic
	dataSectors[numSectors] = freeMap->Find();
	DEBUG('f', "Adding sector %d to the direct block\n", dataSectors[numSectors]);
	numSectors += 1;
      }
    }
  }
}


// Creates a single indirect block, if one does not already exist.
void
FileHeader::CreateSingleIndirectBlock(int newSize, BitMap* freeMap)
{
  // Create a sector for the indirect block
  if (singleIndirectSector == 0) {
    Indirect* singleIndirect = new Indirect;
    singleIndirectSector = freeMap->Find();
    DEBUG('f', "**** Creating an indirect at sector %d\n", singleIndirectSector);
    singleIndirect->numSectors = 0;
    synchDisk->WriteSector(singleIndirectSector, (char *)singleIndirect);
  }
}


// Creates a double indirect block if one does not already exist. Otherwise it
// retrieves the current double indirect block for this file header.
//
// After this, create indirect block until our allocation covers "newSize" which
// is the new size of the current file.
void
FileHeader::AllocateDoubleIndirectBlock(int newSize, BitMap* freeMap)
{
  int allocated = -1;
   // Create a double indirect.
  Indirect *doubleIndirect = new Indirect;

  if (doubleIndirectSector == 0) {
    doubleIndirectSector = freeMap->Find();

    DEBUG('f', "*** Creating a double indirect at sector %d\n", doubleIndirectSector);

    doubleIndirect->numSectors = 0;
    synchDisk->WriteSector(doubleIndirectSector, (char *)doubleIndirect);
  } else {
    synchDisk->ReadSector(doubleIndirectSector, (char *)doubleIndirect);
  }
 
  int currentIndirect = 0;

  while(allocated != 0)
  {
    ASSERT(currentIndirect <= doubleIndirect->numSectors);
    Indirect* singleIndirect = new Indirect;
 
    if (doubleIndirect->dataSectors[currentIndirect] == 0)
    {
      int indSector = freeMap->Find();

      DEBUG('f', "Creating an indirect at sector %d\n", indSector);

      singleIndirect->numSectors = 0;
      doubleIndirect->dataSectors[doubleIndirect->numSectors] = indSector;
      doubleIndirect->numSectors += 1;

      synchDisk->WriteSector(doubleIndirectSector, (char *)doubleIndirect);
      synchDisk->WriteSector(indSector, (char *)singleIndirect);
    } else {
      synchDisk->ReadSector(doubleIndirect->dataSectors[currentIndirect], (char *)singleIndirect);
    }

    int start = (NumDirect * SectorSize) + (NumIndirect * SectorSize) 
      + (currentIndirect * (NumIndirect * SectorSize));

    allocated = AllocateIndirectSpace(newSize, doubleIndirect->dataSectors[currentIndirect], start, freeMap);
    currentIndirect++;
  }
}



// Allocates space in an indirect block until space in the 
// block runs out, or all of the bytes have been allocated,
// whatever comes first.
int
FileHeader::AllocateIndirectSpace(int newSize, int sector, int start, BitMap* freeMap)
{
  DEBUG('f', "Allocating indirect space. Bytes: %d, Sector: %d, StartPoint: %d\n", newSize, sector, start);
  DEBUG('f', "File info: total bytes: %d, total sectors: %d\n", numBytes, numSectors);
  
  int end = start + (NumIndirect * SectorSize);
  Indirect* indirect = new Indirect;

  synchDisk->ReadSector(sector, (char *)indirect);

  // While there is room left in the indirect, just expand the size of the
  // current sector, or add more if the block does not have enough.
  while (numBytes >= start && numBytes < end) {
    if (newSize <= (numSectors * SectorSize)) {
      numBytes = newSize;
      break;
    } else {
      numBytes = (numSectors * SectorSize);
      if (indirect->numSectors < NumIndirect) {
	indirect->dataSectors[indirect->numSectors] = freeMap->Find();
	DEBUG('f', "# Adding sector %d to the indirect block\n", indirect->dataSectors[indirect->numSectors]);
	indirect->numSectors += 1;
	numSectors += 1;
      }
    }
  }
  synchDisk->WriteSector(sector, (char *)indirect);
  return newSize - numBytes;

}


// Setter for the file header sector
void 
FileHeader::SetSector(int sector)
{
  headerSector = sector;
}


// Getter
int 
FileHeader::GetSector()
{
  return headerSector;
}

#endif


//----------------------------------------------------------------------
// FileHeader::Deallocate
// 	De-allocate all the space allocated for data blocks for this file.
//
//	"freeMap" is the bit map of free disk sectors
//----------------------------------------------------------------------

#ifdef CHANGED
void 
FileHeader::Deallocate(BitMap *freeMap)
{
    for (int i = 0; i < numSectors; i++) {
      int s = GetSectorPhysicalAddress(i);
      ASSERT(freeMap->Test(s));  // ought to be marked!
      freeMap->Clear(s);
    }
    if (singleIndirectSector != 0) { 
      if (freeMap->Test(singleIndirectSector)) freeMap->Clear(singleIndirectSector);
    }

    if (doubleIndirectSector != 0) {
      if (freeMap->Test(doubleIndirectSector)) freeMap->Clear(doubleIndirectSector);
    }
}
#endif

//----------------------------------------------------------------------
// FileHeader::FetchFrom
// 	Fetch contents of file header from disk. 
//
//	"sector" is the disk sector containing the file header
//----------------------------------------------------------------------

void
FileHeader::FetchFrom(int sector)
{
    synchDisk->ReadSector(sector, (char *)this);
}

//----------------------------------------------------------------------
// FileHeader::WriteBack
// 	Write the modified contents of the file header back to disk. 
//
//	"sector" is the disk sector to contain the file header
//----------------------------------------------------------------------

void
FileHeader::WriteBack(int sector)
{
    synchDisk->WriteSector(sector, (char *)this); 
}

//----------------------------------------------------------------------
// FileHeader::ByteToSector
// 	Return which disk sector is storing a particular byte within the file.
//      This is essentially a translation from a virtual address (the
//	offset in the file) to a physical address (the sector where the
//	data at the offset is stored).
//
//	"offset" is the location within the file of the byte in question
//----------------------------------------------------------------------

int
FileHeader::ByteToSector(int offset)
{
  int localSector = offset / SectorSize;
  return GetSectorPhysicalAddress(localSector);

}

//----------------------------------------------------------------------
// FileHeader::FileLength
// 	Return the number of bytes in the file.
//----------------------------------------------------------------------

int
FileHeader::FileLength()
{
    return numBytes;
}


#ifdef CHANGED
// Translates the virtual sector into a physical sector.
//
// For the double indirect, need to load the indirect from the
// sector, find the relevant single indirect, load it, and then find
// the correct sector by offsetting the virtual sector by the starting
// point of the single indirect within the double indirect blocks.
int 
FileHeader::GetSectorPhysicalAddress(int localSector)
{
  if(localSector < NumDirect) return(dataSectors[localSector]);
  else if (localSector < (NumDirect + NumIndirect))
  {
    ASSERT(singleIndirectSector != 0);
    ASSERT(localSector < (NumDirect + NumIndirect));
    Indirect* singleIndirect = new Indirect;
    synchDisk->ReadSector(singleIndirectSector, (char *)singleIndirect);
    return singleIndirect->dataSectors[localSector - NumDirect];
  }
  else {
    
    ASSERT(doubleIndirectSector != 0);
    ASSERT(numSectors > (NumDirect + NumIndirect));
    
    Indirect* doubleIndirect = new Indirect;

    synchDisk->ReadSector(doubleIndirectSector, (char *)doubleIndirect);
    
    int single = (localSector - (NumDirect + NumIndirect))/NumIndirect;

    Indirect* ind = new Indirect;
    synchDisk->ReadSector(doubleIndirect->dataSectors[single], (char *)ind);
    int pos = (localSector - (NumDirect + NumIndirect)) % NumIndirect;

    return ind->dataSectors[pos];
  }
}


//----------------------------------------------------------------------
// FileHeader::Print
// 	Print the contents of the file header, and the contents of all
//	the data blocks pointed to by the file header.
//----------------------------------------------------------------------

void
FileHeader::Print()
{
    int i, j, k;
    char *data = new char[SectorSize];

    DEBUG('f', "NumDirect: %d, numSectors: %d\n", NumDirect, numSectors);
    printf("FileHeader contents.  File size: %d. Sectors: %d.  File blocks:\n", numBytes, numSectors);
    for (i = 0; i < numSectors; i++) {
      int sec =  this->GetSectorPhysicalAddress(i);
      if (i < NumDirect) {
	printf("%d ", sec);
      } else if (i < (NumDirect + NumIndirect))
	printf("*%d* ", sec);	
      else 
	printf("**%d** ", sec);
    } 
    
    printf("\nFile contents:\n");
    for (i = k = 0; i < numSectors; i++) {
	synchDisk->ReadSector(this->GetSectorPhysicalAddress(i), data);
      
        for (j = 0; (j < SectorSize) && (k < numBytes); j++, k++) {
	    if ('\040' <= data[j] && data[j] <= '\176')   // isprint(data[j])
		printf("%c", data[j]);
            else
		printf("\\%x", (unsigned char)data[j]);
	}
        printf("\n");
      
    }
    delete [] data;
}
#endif
