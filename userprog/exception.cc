// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include <iostream>
#include "copyright.h"
#include "system.h"
#include "list.h"
#include "syscall.h"
#include "process.h"
#include "syncconsole.h"

#ifdef CHANGED
// COMP 305 Project #2
// Copyright David Petrie 2008
static List* Processes;
static Process* currentProcess;
static SynchConsole* console;

//----------------------------------------------------------------------
// The InitExceptions function is used to initialize various useful things
//----------------------------------------------------------------------
void
InitExceptions(){
  console = new SynchConsole(NULL, NULL);
  Processes = new List();
}

// Add a new process into the list and make it the current process
void
InitProcess(Process* process)
{
    Processes->Append(process);
    currentProcess = process;
}



// Ensures that the forked thread begins execution at the correct position.
void ForkUserThread(int funcPtr)
{
  DEBUG('t', "Setting machine PC to funcPtr for thread %s: 0x%x...\n", currentThread->getName(), funcPtr);
 
  currentThread->space->InitRegisters();
  currentThread->space->RestoreState();
  
  // update the stack register
  machine->WriteRegister(StackReg, currentThread->space->GetNumPages() * PageSize - 16);

  // Set the program counter to the appropriate place indicated by funcPtr...
  machine->WriteRegister(PCReg, funcPtr);
  machine->WriteRegister(NextPCReg, funcPtr + 4);
  machine->Run();
}



// increment the PC
void IncrementPC()
{
  int pc = machine->ReadRegister(PCReg);
  machine->WriteRegister(PrevPCReg, pc);
  pc = machine->ReadRegister(NextPCReg);
  machine->WriteRegister(PCReg, pc);
  pc += 4;
  machine->WriteRegister(NextPCReg, pc);
}



//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------
// "The PC is just a register, accessible to you through ReadRegister and 
// WriteRegister. See the definitions of ``User program CPU state'' in 
// machine.h for the register number of the PC. Each MIPS memory address, 
// including the PC, points to a byte of memory, and each instruction is 
// several bytes long, so ``increment'' the PC does not mean to add 1. 
// Look in mipssim.cc to find the right number to add to the PC. Also, the 
// use of delayed branching in the MIPS requires a separate NextPC register, 
// and for debugging purposes Nachos maintains a PrevPC, both of which 
// must be updated appropriately. See the Nachos Road Map section on 
// experience with multiprogramming for the correct code to increment the 
// PC. "
//
// Each system call has a return value. If this value is false at any time
// it means there was an error in the user program. The response here should
// be to just shut down the process and free the memory. However, since
// nachos runs the user program in the "main" thread, we just call 
// interrupt->halt() in order to shut down the program.
void
ExceptionHandler(ExceptionType which)
{
  bool result = true;
  int type = machine->ReadRegister(2);
  int arg1 = machine->ReadRegister(4);
  int arg2 = machine->ReadRegister(5);
  int arg3 = machine->ReadRegister(6);
  int arg4 = machine->ReadRegister(7);

  DEBUG('a', "Syscall Args %d, %d, %d, %d\n", arg1, arg2, arg3, arg4);

  if (which == SyscallException)
  {
    switch (type) {
    case SC_Halt:
      // Need to deal with any data structures here.
      DEBUG('a', "Shutdown, initiated by user program.\n");
      interrupt->Halt();
      break;
    case SC_Exit:
      DEBUG('a', "Exit, initiated by user program.\n");
      // If there is only one thread left in the process then delete the
      // process and halt.
      if (currentProcess->ExitProcess(arg1)) {
	delete currentProcess;
	return;
      }
      break;
    case SC_Create: 
      result = currentProcess->FileCreate(arg1);
      break;
    case SC_Open:
      result = currentProcess->FileOpen(arg1);
      break;
    case SC_Read:
      result = currentProcess->FileRead(arg1, arg2, arg3);
      break;
    case SC_Write:
      result = currentProcess->FileWrite(arg1, arg2, arg3);
      break;
    case SC_Close:
      result = currentProcess->FileClose(arg1);
      break;
    case SC_Fork:
      result = currentProcess->ProcessFork(arg1);
      break;
    case SC_Yield:
      currentProcess->ProcessYield();
      result = true;
      break;
    default:
      printf("Unexpected user mode exception %d %d\n", which, type);
      ASSERT(FALSE);
      break;
    }
  } else {
    printf("Unexpected user mode exception %d %d\n", which, type);
    ASSERT(FALSE);
  }
  IncrementPC();
  if (result == false) {
    DEBUG('p', "ERROR in user program - shutting down process.\n");
    interrupt->Halt();
    delete currentProcess;
  }
}




// Process constructor
Process::Process(char* n)
  {
    name = n;
    processThread = currentThread;
    threads = new List();
    threadCount = 0;
    fileCounter = 0;
  }



// Delete all the threads associated with this process.
  Process::~Process()
  {
    Thread* threadToDelete;
    while(!threads->IsEmpty()) {
      threadToDelete = (Thread *)threads->Remove();
      delete threadToDelete;
    }
    delete threads;
    delete openFileTable;
  }



  // Three situations:
  // - If the exiting thread is the main process that initialised this process
  //   and there are no other threads running, then return true. The exception
  //   handler will delete the process.
  // - If the exiting thread is the main thread that initialised the process
  //   but there are other threads running, then simply finish the current thread.
  // - If a forked thread is exiting, then decrement the thread count and 
  //   finish the thread.
  bool Process::ExitProcess(int status) 
  {
    if (currentThread == processThread) {
      if (threadCount == 0) {
	DEBUG('p', "Exiting the main thread\n");
	interrupt->Halt();
	return true;
      } else {
	currentThread->Finish();
	return false;
      }
    } else {
      ASSERT(currentThread != this->processThread);
      DEBUG('p', "Exiting a forked thread.\n");
      threadCount--;
      currentThread->Finish();
      return false;
    }
  }



   // Create a file with the name stored in machine memory at ptrFileName.
  bool Process::FileCreate(int ptrFileName)
  {
    char* fileName = &machine->mainMemory[ptrFileName];
    if (fileName == NULL) {
      // This error is actually serious enough to warrant a halt.
      DEBUG('p', "Could not find file name in memory.\n");
      return false;
    }
    if (strlen(fileName) == 0) {
      DEBUG('p', "File name had a length of 0.\n");
      return false;
    }
      
    DEBUG('p', "Creating a file %s\n", fileName);
    
    bool result = fileSystem->Create(fileName, 100);
    if (result)
    {
     DEBUG('p', "File %s was successfully created\n", fileName);
    } else {
     DEBUG('p', "error creating file %s\n", fileName);
    }
    
    return result;
  }



  // Open a file
  // 
  // Must write a unique id for the file back to a register.
  bool Process::FileOpen(int ptrFileName)
  {
    // Too many files open?
    //
    // might be better simply to block the thread on a condition variable
    // until one of them closes...
    if (fileCounter - FID_OFFSET >= MAX_OPEN_FILES)
    {
      DEBUG('p', "Too many files open.\n");
      return false;
    }

    char* fileName = &machine->mainMemory[ptrFileName];
    if (fileName == NULL)
    {
      DEBUG('p', "Could not find file name string reference in memory.\n");
      return false;
    }

    if (strlen(fileName) == 0)
    {
      DEBUG('p', "Filename had a length of zero.\n");
      return false;
    }

    DEBUG('p', "Opening a file %s\n", fileName);   

    OpenFile* file = fileSystem->Open(fileName);
    if (file == NULL)
    {
      DEBUG('p', "File system could not find the file specified.\n");
      return false;
    }
    openFileTable[fileCounter] = file;

    machine->WriteRegister(2, fileCounter + FID_OFFSET);
    fileCounter++;
  }



  // Close a file
  //
  // We just remove it from the list of open files.
  bool Process::FileClose(int fid)
  {
    if (openFileTable[fid - FID_OFFSET] == NULL) {
      DEBUG('p', "Could not find an open file with that id...\n");
      return false;
    }
    delete openFileTable[fid - FID_OFFSET];
    fileCounter--; // bug here - not necessarily the next file id...
    return true;
  }
  


// Write a string to a file. 
//
// The main string is stored in memory at ptrBuffer.
//
// Need to check if an attempt was made to write to the console...
//
// At the moment, we're making an assumption that no other
// process are running (processes as distinct to threads).
//
// Open files should be stored in a global structure with
// locks. May even be best as the structure used by the producer
// consumer thing - if we run out of file space then process blocks
// until another process drops the file via the close method.
//
// For now though, assume only one process.
bool Process::FileWrite(int ptrBuffer, int bufferSize, int fid)
{
  char *buffer = &machine->mainMemory[ptrBuffer];

  if (buffer == NULL)
  {
      DEBUG('p', "Cannot find string to write.\n");
      return false;    
  }

  DEBUG('p', "Attempting to write %s to file %d\n", buffer, fid);
  if (fid == ConsoleOutput)
  {
    if (console == NULL) console = new SynchConsole(NULL, NULL);
    console->WriteLine(buffer, bufferSize + 1);
  } 
  else if (fid == ConsoleInput)
    {
      DEBUG('p', "Cannot write to console input.\n");
      return false;
    } 
  else
  {
    OpenFile* file = openFileTable[fid - FID_OFFSET];
    if (file == NULL) {
       DEBUG('p', "File does not exist!\n");
       return false;
    }
    file->Write(buffer, bufferSize + 1);
  }
  return true;
}



// Read a string from file (or stdin) and put it back into machine memory.
//
// NOTE: buffersize is incremented by one so we can collect newlines from the stdin.
bool Process::FileRead(int ptrBuffer, int bufferSize, int fid)
{
  if (bufferSize == 0)
    {
      DEBUG('p', "Cannot read zero bytes.\n");
      return false;
    }

  char *buffer = (char *)malloc(sizeof(char *) * (bufferSize +1));
  DEBUG('p', "Attempting to read %d bytes from file %d\n", bufferSize, fid);
  
  if (fid == ConsoleInput)
  {
    // Get the console and read from it.
    if (console == NULL) console = new SynchConsole(NULL, NULL);
    console->ReadLine(buffer, bufferSize + 1);
  }
  else if (fid == ConsoleOutput)
  {
    // Can't read from console output. 
    DEBUG('p', "Cannot read from console output.\n");
    return false;
  }
  else 
  {
    // Read bytes from the file.
    OpenFile* file = openFileTable[fid - FID_OFFSET];
    if (file == NULL) {
      DEBUG('p', "File does not exist!\n");
      return false;
    }
    file->Read(buffer, bufferSize + 1);
  }
  int len = strlen(buffer);
  DEBUG('p', "Read string %s with len %d\n", buffer, len);

  strcpy(&machine->mainMemory[ptrBuffer], buffer);
  machine->WriteRegister(2, len);
  return true;
}



// Fork the process
//
// Within this function we want to create a new stack, and then attach
// it to a new kernal thread.
//
// The fork simply creates a new thread with a reference to the same address 
// space as the current kernal thread. It then creates a new stack in this
// address space, assuming enough memory is available.
// 
// There's no need to worry about the registers since the thread code, in 
// the words of the comment in the initRegisters
// function, "will be saved/restored into the currentThread->userRegisters
// when this thread (that is, the kernal thread) is context switched out."
//
// The kernal thread forks to the global function ForkUserThread which is
// described above.
bool Process::ProcessFork(int funcPtr)
{
  DEBUG('p', "Forking, arg 0x%x \n", funcPtr);

  threadCount++;

  char* tname = (char *)malloc(sizeof(char) * (16 + strlen(this->name)));
  sprintf(tname, "Thread - %s %d", this->name, threadCount);
  Thread* thread = new Thread(tname);

  // Use the current thread address space
  // and create a new stack within the space...
  thread->space = currentThread->space;
  if (false == thread->space->CreateStack())
  {
    delete thread;
    DEBUG('p', "Create stack failed - not enough memory available.\n");
    return false;
  }

  this->threads->Append(thread);

  thread->Fork(ForkUserThread, funcPtr);
  return true;
}
  


// Yield the current process.
//
// When this is called, the thread that replaces current thread
// will be "woken" up by the scheduler. This means all the registers
// (including the program counter) will be restored.
//
// The thread will return execution to HandleException, and will
// immediately increment the PC.
//
// In other words, we don't need to do anything more here than call
// Yield on the current thread.
void Process::ProcessYield()
{
  DEBUG('p', "Thread yielding %s\n", currentThread->getName());
  currentThread->Yield();
}
  
#endif
