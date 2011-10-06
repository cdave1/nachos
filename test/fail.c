/* 
 *	fail.c - stresstest of the system call error handling abilities...
 *      Each function should cause the process to finish.
 *      Error messages can be viewed by using the debug flag -p
 */

#include "syscall.h"

int
main()
{
  //ExitTest();
  //CreateFileEmptyName();
  //WriteFileFail();
  //CreateAndOpenMany();
  //WriteNothing();
  TooManyForks();
  //OpenNonExistantFile();
}

void CreateFileEmptyName()
{
  Create("");
}

// Creates one file, then opens it too many times, causing the process to exit.
void CreateAndOpenMany()
{
  OpenFileId fid;
  int i = 0;
  Create("testfile1");
  while(i++ <= 102) fid = Open("testfile1");
}

// Create a valid file,  but mangle the fid when writing...
void WriteFileFail()
{
  OpenFileId fid;
  Create("testfile1");
  fid = Open("testfile1");
  Write("test\n", 5, fid+50);
}

// Write zero length string to the file.
void WriteNothing()
{
  OpenFileId fid;
  Create("testfile1");
  fid = Open("testfile1");
  Write("", 0, fid);
}

//Should tell us that the file does not exist.
void OpenNonExistantFile()
{
  OpenFileId fid;
  fid = Open("this_file_does_not_exist");
}

// Handle for TooManyForks, below...
void ForkHandle()
{
  Yield();
  Write("Fork handle\n", 12, ConsoleOutput);
  Yield(); 
  Exit(0);
}

// Should run out of memory after 3-4 calls to Fork
void TooManyForks()
{
  int i = 0;
  while(i++ < 8) Fork(&ForkHandle);
}

// Should just exit - the write system call should never 
// be reached.
void ExitTest()
{
  Exit(0);
  Write("Fail\n", 5, ConsoleOutput);
  Exit(0);
}
