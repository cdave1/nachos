/* helloworld.c
 *	Simple program to see if we can write "Hello World".
 */

#include "syscall.h"

int
main()
{
  Write("Hello World\n", 12, ConsoleOutput);
  Halt();
  /* not reached */
}
