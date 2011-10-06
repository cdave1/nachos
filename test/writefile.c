/* writefie.c
 *	Program to write a file with input from the console.
 */

#include "syscall.h"
#define BUFSIZE 20
int
main()
{
  OpenFileId fid;
  char buffer[BUFSIZE];
  int i, n;

  Create("newfile");
  fid = Open("newfile");

  /* Read six buffers, we have no end of file signal. */

  for (i =0; i < 6; i++) {
    Read(buffer, BUFSIZE, ConsoleInput);
    Write(buffer, BUFSIZE, fid);
  }
  Close(fid);
  Halt();
  /* not reached */
}
