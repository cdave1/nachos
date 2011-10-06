// David Petrie
//
// BoundedBuffer
//
// Wraps an array around a lock and a condition variable so
// that many threads can concurrently modify the contents of an
// array of char.
//
// The array itself is bounded, in that it has a fixed capacity,
// and the insertion point wraps around to the start of the 
// buffer when it gets to the end.

#ifdef CHANGED
#include "copyright.h"
#include "boundedbuffer.h"
#include "synch.h"
#include "system.h"


BoundedBuffer::BoundedBuffer(int c)
{
  mutex = new Lock("bounded buffer mutex lock");
  itemCount = 0;
  capacity = c;
  in = 0;
  out = 0;

  buffer = new char[capacity];
  inCS = 0;
  empty = new Condition("EMPTY");
  full = new Condition("FULL");
}


BoundedBuffer::~BoundedBuffer()
{ 
  delete buffer;
  delete mutex;
  delete empty;
  delete full;
}


// Acquire the lock and then block on condition "full" if there is no
// spare room in the buffer.
//
// After the critical section, signal any threads waiting for something
// to appear in the buffer, and release the lock.
//
// Invariants to enter critical section:
// - buffer must have empty slots.
// - inCS must be 0 before adding an item to the buffer.
// - inCS must also be 0 immediately before the lock is released.
void BoundedBuffer::Append(char *item)
{
  mutex->Acquire();
  while (itemCount == capacity)
    full->Wait(mutex);

  // *** Critical section
  DEBUG('t', "Thread \"%s\" is ENTERING critical section.\n",  currentThread->getName());
  ASSERT(inCS == 0);
  inCS++;
 
  // insert the item into the buffer
  buffer[in] = *item;
  in = (in + 1) % capacity;
  itemCount++;

  inCS--;
  ASSERT(inCS == 0);
  DEBUG('t', "Thread \"%s\" is EXITING critical section.\n",  currentThread->getName());
  // *** End of critical section

  printf("*** %s added \"%c\" to buffer\n\n", currentThread->getName(), *item);
  empty->Signal(mutex);
  mutex->Release();
}


// Acquire the lock then check if the buffer is empty. If the buffer 
// IS empty, then block the thread on the "empty" condition variable.
//
// When an item is removed, signal any threads blocked on the 
// "full" condition variable, and then release the lock.
//
// Invariants to enter the critical section:
// - buffer must have something in it.
// - inCS must be 0 before removing an item from the buffer.
// - inCS must also be 0 immediately before the lock is released.
char *BoundedBuffer::Take()
{
  char *item;

  mutex->Acquire();
  while(itemCount == 0)
    empty->Wait(mutex);
  
  // *** Critical section
  DEBUG('t', "Thread \"%s\" is ENTERING critical section.\n",  currentThread->getName());
  ASSERT(inCS == 0);
  inCS++;

  // Consume an item from the buffer
  item = &buffer[out];
  out = (out + 1) % capacity;
  itemCount--;

  inCS--;
  ASSERT(inCS == 0);
  DEBUG('t', "Thread \"%s\" is EXITING critical section.\n",  currentThread->getName());
  // *** End of critical section

  printf("*** %s took \"%c\" from buffer\n\n", currentThread->getName(), *item);
  DEBUG('b', "Current buffer contents: %s\n", buffer);

  full->Signal(mutex);
  mutex->Release();
  return item;
}
#endif
