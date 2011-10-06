#include <iostream>
#include "process.h"
#include "system.h"
#include "list.h"
#include "openfile.h"
#include "addrspace.h"

extern void InitExceptions();
extern void InitProcess(Process* process);
extern void ForkUserThread(int funcPtr);
extern void IncrementPC();


//----------------------------------------------------------------------
// StartProcess
// 	Run a user program.  Open the executable, load it into
//	memory, and jump to it.
//----------------------------------------------------------------------


void
StartProcess(char *filename)
{
  
    OpenFile *executable = fileSystem->Open(filename);
    AddrSpace *space;

    if (executable == NULL) {
	printf("Unable to open file %s\n", filename);
	return;
    }

    InitExceptions();

    space = new AddrSpace(executable);
  
    currentThread->space = space;

    Process* process = new Process(filename);

    InitProcess(process);

    delete executable;			// close file

    space->InitRegisters();		// set the initial register values
    space->RestoreState();		// load page table register

    machine->Run();			// jump to the user progam
    ASSERT(FALSE);			// machine->Run never returns;
					// the address space exits
					// by doing the syscall "exit"
}
