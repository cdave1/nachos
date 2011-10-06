#include "syscall.h"

void forkOne()
{
  Exit(0);
}

void forkTwo()
{
  Exit(0);
}

int
main()
{
  Fork(&forkOne);
  Fork(&forkTwo);
  Exit(0);
  Halt();
  /* not reached */
}
