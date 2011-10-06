//----------------------------------------------------------------------
// SynchConsole
//    Routines to synchronously access the console.  The console itself
//    is asynchronous.
//
//    A lock is used to ensure one read or write is done at a time.
//----------------------------------------------------------------------

#include "console.h"
#include "synch.h"

static Semaphore *readAvail;
static Semaphore *writeDone;

static void ReadAvail(int arg) { readAvail->V(); }
static void WriteDone(int arg) { writeDone->V(); }

class SynchConsole {
public:
  SynchConsole(char* readFile, char* writeFile);
  ~SynchConsole();
  void ReadLine(char *databuf,int length);
  void WriteLine(char *databuf,int length);
  
private:
  Console *console;
  Lock *lock;
};

