// David Petrie
// 300148086
//
// Bridge.cc
//
// Data structure that allows concurrent access to a Bridge.
//
// Threads arrive at the bridge, cross, then exit. The
// synchronisation primitives ensure that there are no
// collisions on the bridge, or that not too many vehicles
// are on the bridge at the same time.
#ifdef CHANGED
#include "system.h"
#include "bridge.h"
#include "synch.h"

Bridge::Bridge(int max)
{
  full = new Condition("Bridge full");
  mutex = new Lock("Bridge");

  currDirection = 0;
  maxCars = max;
  totalCars = 0;
  inCS = 0;
}


Bridge::~Bridge()
{
  delete full;
  delete mutex;
}


// Car arrives at the bridge.
//
// Invariants for the critical section:
// - There are no cars on the bridge
// - OR there are less than "maxCars" on the bridge, and they 
//   are travelling in the same direction as the passed value.
void Bridge::ArriveBridge(int direction)
{
  mutex->Acquire();
  printf("%s arriving at bridge (direction: %d)\n", currentThread->getName(), direction);

  while ((totalCars > 0) && ((totalCars == maxCars) || (currDirection != direction)))
  {
    printf("- %s waiting to enter bridge (direction: %d) - ", currentThread->getName(), direction);
    printf("%d cars on bridge in dir %d\n", totalCars, currDirection);
    full->Wait(mutex);
  }
  printf("%s entering bridge (direction: %d)\n", currentThread->getName(), direction);

  DEBUG('t', "Thread \"%s\" is ENTERING critical section \n", currentThread->getName());
  ASSERT(inCS == 0);
  inCS++;
  totalCars++;
  currDirection = direction;
  inCS--;
  ASSERT(inCS == 0);
  DEBUG('t', "Thread \"%s\" is EXITING critical section.\n",  currentThread->getName());

  mutex->Release();
}


// Just some debug trivia as the car crosses the bridge...
void Bridge::CrossBridge(int direction)
{
  DEBUG('t', "%s crossing bridge (direction: %d)\n", currentThread->getName(), direction);
}


// Thread wants to exit the bridge.
//
// Simply needs to acquire the lock in order to exit the bridge.
// Also signals any threads blocked on a full bridge.
void Bridge::ExitBridge(int direction)
{
  mutex->Acquire();
  printf("%s exiting bridge (direction: %d)\n", currentThread->getName(), direction);

  DEBUG('t', "Thread \"%s\" is ENTERING critical section.\n",  currentThread->getName());
  ASSERT(inCS == 0);
  inCS++;
  totalCars--;
  inCS--;
  ASSERT(inCS == 0);
  DEBUG('t', "Thread \"%s\" is EXITING critical section.\n",  currentThread->getName());

  full->Signal(mutex);
  mutex->Release();
}

#endif
