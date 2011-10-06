/* forktest.c
 *	Simple program to see if we can fork a user thread.
 */

#include "syscall.h"

void secondThread() {
  Write("Goodbye World\n", 14, ConsoleOutput);
  Yield();
  Exit(0);
}

int
main()
{
  Fork(&secondThread);
  Write("Hello World\n", 12, ConsoleOutput);
  Yield();
  Write("Hello World\n", 12, ConsoleOutput);
  Exit(0);
  /* not reached */
}
