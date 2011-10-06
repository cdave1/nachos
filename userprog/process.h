#include "copyright.h"
#include "thread.h"
#include "system.h"
#include "addrspace.h"
#include "list.h"
#include "openfile.h"

#define MAX_OPEN_FILES 100
#define FID_OFFSET 2 // So there are no clashes with the console file ids...

void StartProcess(char *filename);



// Process
//
// All the system calls are on the process (though I guess they do not need to be).
//
// 
class Process {
 public:
  //Process(char* n, Thread* pThread);
  Process(char* n);
  ~Process();

  //bool Start();

  bool ExitProcess(int status);
  
  // Create a file
  bool FileCreate(int ptrFileName);

  // Open a file
  bool FileOpen(int ptrFileName);

  // Close a file
  bool FileClose(int ptrFileName);
  
  // Write a string to a file.
  bool FileWrite(int ptrBuffer, int bufferSize, int fid);

  // Read a character from a file
  bool FileRead(int ptrBuffer, int bufferSize, int fid);

  // Fork the process
  bool ProcessFork(int fnPtr);

  // Yield the process
  void ProcessYield();
    

 private:
    int processNumber;
    char* name;
    Thread* processThread;
    List* threads;
    int threadCount;
    int fileCounter;
    
    OpenFile* openFileTable[MAX_OPEN_FILES];
};

#endif
