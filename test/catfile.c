/* catfie.c
 *	Program to print a file on the console.
 */

#include "syscall.h"
#define BUFSIZE 100
int
main()
{
  OpenFileId fid;
  char buffer[BUFSIZE];
  int n;

  fid = Open("Makefile");
  while ((n = Read(buffer, BUFSIZE, fid)) > 0) {
    Write(buffer, n, ConsoleOutput);
  }
  Close(fid);
  Halt();
  /* not reached */
}
