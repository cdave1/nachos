#include "syncconsole.h"

//----------------------------------------------------------------------
// SynchConsole::SynchConsole(readfile,writefile)
//    Initialize the synchronous interface, which in turn synchronizes
//    the physical console.  Pass NULL file names to use stdin and
//    stdout.
//----------------------------------------------------------------------

SynchConsole::SynchConsole(char *readFile, char *writeFile)
{
  lock = new Lock("Synch console lock");
  readAvail = new Semaphore("Synch console read semaphore",0);
  writeDone = new Semaphore("Synch console write semaphore",0);
  console = new Console(readFile,writeFile,ReadAvail,WriteDone,0);
}

//----------------------------------------------------------------------
//  SynchConsole::~SynchConsole()
//     Clean up the console.
//----------------------------------------------------------------------

SynchConsole::~SynchConsole()
{
  delete console;
  delete lock;
  delete readAvail;
  delete writeDone;
}

void
SynchConsole::ReadLine(char *databuf,int length)
{
  int idx = 0;
  lock->Acquire();              // sole access to the console
  for (; length>0; length--) {
    DEBUG('a',"getting char from console\n");
    readAvail->P();                         // wait for interrupt
    databuf[idx++] = console->GetChar();    // input one character at a time
  }
  lock->Release();
}

void
SynchConsole::WriteLine(char *databuf,int length)
{
  int idx = 0;
  lock->Acquire();              // sole access to the console
  for (; length>0; length--) {
    DEBUG('a',"Putting char to console\n");
    console->PutChar(databuf[idx++]);    // output one character at a time
    writeDone->P();                      // wait for interrupt
  }
  lock->Release();
}
