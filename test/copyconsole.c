/* copyconsole.c
 *	Simple program to copy the input typed to the console to
 *      the output on the console.  Everything is done as fixed
 *      length lines of 12 characters.
 */

#include "syscall.h"

int
main()
{
  char buffer[12];
  Read(buffer, 12, ConsoleInput);
  Write(buffer, 12, ConsoleOutput);
  Halt();
  /* not reached */
}
