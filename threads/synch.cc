// synch.cc 
//	Routines for synchronizing threads.  Three kinds of
//	synchronization routines are defined here: semaphores, locks 
//   	and condition variables (the implementation of the last two
//	are left to the reader).
//
// Any implementation of a synchronization routine needs some
// primitive atomic operation.  We assume Nachos is running on
// a uniprocessor, and thus atomicity can be provided by
// turning off interrupts.  While interrupts are disabled, no
// context switch can occur, and thus the current thread is guaranteed
// to hold the CPU throughout, until interrupts are reenabled.
//
// Because some of these routines might be called with interrupts
// already disabled (Semaphore::V for one), instead of turning
// on interrupts at the end of the atomic operation, we always simply
// re-set the interrupt state back to its original value (whether
// that be disabled or enabled).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "synch.h"
#include "system.h"

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore::Semaphore(char* debugName, int initialValue)
{
    name = debugName;
    value = initialValue;
    queue = new List;
}

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore::~Semaphore()
{
    delete queue;
}

//----------------------------------------------------------------------
// Semaphore::P
// 	Wait until semaphore value > 0, then decrement.  Checking the
//	value and decrementing must be done atomically, so we
//	need to disable interrupts before checking the value.
//
//	Note that Thread::Sleep assumes that interrupts are disabled
//	when it is called.
//----------------------------------------------------------------------

void
Semaphore::P()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts
    
    while (value == 0) { 			// semaphore not available
	queue->Append((void *)currentThread);	// so go to sleep
	currentThread->Sleep();
    } 
    value--; 					// semaphore available, 
						// consume its value
    
    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
}

//----------------------------------------------------------------------
// Semaphore::V
// 	Increment semaphore value, waking up a waiter if necessary.
//	As with P(), this operation must be atomic, so we need to disable
//	interrupts.  Scheduler::ReadyToRun() assumes that threads
//	are disabled when it is called.
//----------------------------------------------------------------------

void
Semaphore::V()
{
    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    thread = (Thread *)queue->Remove();
    if (thread != NULL)	   // make thread ready, consuming the V immediately
	scheduler->ReadyToRun(thread);
    value++;
    (void) interrupt->SetLevel(oldLevel);
}





#ifdef CHANGED

// A lock wraps around a semaphore.
Lock::Lock(char* debugName) 
{
  name = debugName;
  lockOwner = NULL;
  sem = new Semaphore(debugName, 1);
}


Lock::~Lock() 
{
  delete sem;
}


// Current thread attempts to acquire the lock.
//
// Thread will sleep if another thread has the lock.
void Lock::Acquire() 
{
  IntStatus oldLevel = interrupt->SetLevel(IntOff);
  DEBUG('t', "Thread \"%s\" is acquiring lock.\n", currentThread->getName());
  sem->P();
  lockOwner = currentThread;
  (void) interrupt->SetLevel(oldLevel);
}


// Current thread releases the lock, and wakes another thread blocked on the
// lock.
void Lock::Release() 
{
  IntStatus oldLevel = interrupt->SetLevel(IntOff);
  DEBUG('t', "Thread \"%s\" is RELEASING lock.\n", currentThread->getName());
  sem->V();
  lockOwner = NULL;
  (void) interrupt->SetLevel(oldLevel);
}


bool Lock::isHeldByCurrentThread()
{
  return (lockOwner == currentThread);
}


// Just returns a pointer to the thread that holds the lock.
Thread* Lock::getOwner()
{
  return lockOwner;
}



// Condition lock is just a binary semaphore.
//
// A lot of the condition variable code is borrowed from the Semaphore
// above.
//
// Engineering note: My initial approach here was to use a semaphore
// to implement the condition lock. However, there was no easy 
// way to ensure that the thread awoken by the semaphore is the one we 
// actually want to wake up. Far better to have the condition lock 
// manage the queue of processes itself.
//
// Because of this, the condition is almost identical to the
// semaphore, with some additional code to ensure that the thread
// being woken or put to sleep is indeed the owner of the lock.
Condition::Condition(char* debugName) 
{
  name = debugName;
  queue = new List;
}


Condition::~Condition() 
{
  delete queue;
}


// Wait on the condition variable. If the currentThread owns the lock
// then the thread is added to the condition variable's queue, and
// then put to sleep.
//
// If another thread calls Signal, then this thread will eventually be
// woken up, and will resume by attempting to acquire the lock.
void Condition::Wait(Lock* conditionLock) 
{ 
  IntStatus oldLevel = interrupt->SetLevel(IntOff);
  DEBUG('t', "Thread \"%s\" is waiting on condition \"%s\"\n", currentThread->getName(), name);

  // We want to release the lock, but only if the thread that has the lock
  // is also the thread that is calling Wait.
  Thread* lockOwner = conditionLock->getOwner();
  if (lockOwner != NULL) {
    ASSERT(lockOwner == currentThread);
    queue->Append((void *)currentThread);

    conditionLock->Release();
    DEBUG('t', "Thread \"%s\" is BLOCKED on condition \"%s\"\n", currentThread->getName(), name);
    currentThread->Sleep();
    DEBUG('t', "Thread \"%s\" has woken and is about to get lock.\n", currentThread->getName());
    conditionLock->Acquire();
  }
  (void) interrupt->SetLevel(oldLevel);
}


// Signals on the condition variable.
//
// This will wake a thread blocked on the condition variable.
void Condition::Signal(Lock* conditionLock) 
{
  DEBUG('t', "Thread \"%s\" is signalling processes blocked on condition \"%s\"\n", currentThread->getName(), name);

  Thread *thread;
  IntStatus oldLevel = interrupt->SetLevel(IntOff);

  if (queue->IsEmpty() == false) {
    thread = (Thread *)queue->Remove();
    DEBUG('t', "- woke up thread \"%s\"\n", thread->getName());
    if (thread != NULL) scheduler->ReadyToRun(thread);
  }
  (void) interrupt->SetLevel(oldLevel);
}


// Wakes all threads blocked on the condition variable.
void Condition::Broadcast(Lock* conditionLock) 
{
  Thread *thread;
  IntStatus oldLevel = interrupt->SetLevel(IntOff);

  // TODO: check if the current thread holds the lock
  while (queue->IsEmpty() == false) {
    thread = (Thread *)queue->Remove();
    if (thread != NULL) scheduler->ReadyToRun(thread);
  }
  (void) interrupt->SetLevel(oldLevel);
}


// Read write lock is a synchronisation primitive used
// by the file system
//
// Allows readers and writers to access the file system
// - If readers are reading then writers are blocked. Other
//   writers are simply passed through.
// - If writers are writing then readers are blocked. Other
//   readers can pass through.
//
// Adapted from: http://grommit.com/~ranga/school/cs140/
ReadWriteLock::ReadWriteLock()
{
    rwlock = new Lock("rwlock") ;
    rwcondition = new Condition("rwCondition") ;
    readerCount = 0;
    lockStatus = FREE;
    writeOwner = 0;
}

ReadWriteLock::~ReadWriteLock()
{
    ASSERT(readerCount == 0);
    ASSERT(lockStatus == FREE);
    delete rwlock ;
    delete rwcondition ;
}

void ReadWriteLock::ReadLock()
{
    rwlock->Acquire();
    while (lockStatus == WRITE)
        rwcondition->Wait(rwlock);
    ASSERT(readerCount >= 0);
    if (lockStatus == FREE) {
        ASSERT(readerCount == 0);
        lockStatus = READ;
    }
    readerCount++;
    rwlock->Release();
}

void ReadWriteLock::ReadUnlock()
{
    rwlock->Acquire();
    ASSERT(lockStatus == READ);
    readerCount--;
    ASSERT(readerCount >= 0);
    if (readerCount == 0) {
        lockStatus = FREE;
        rwcondition->Broadcast(rwlock);
    }
    rwlock->Release();
}

void ReadWriteLock::WriteLock()
{
    rwlock->Acquire();
    while (lockStatus != FREE)
        rwcondition->Wait(rwlock);
    ASSERT(readerCount == 0);
    ASSERT(writeOwner == 0);
    writeOwner = currentThread;
    lockStatus = WRITE;
    rwlock->Release();
}

void ReadWriteLock::WriteUnlock()
{
    rwlock->Acquire();
    ASSERT(lockStatus == WRITE);
    ASSERT(readerCount == 0);
    ASSERT(writeOwner == currentThread);
    lockStatus = FREE;
    writeOwner = 0;
    rwcondition->Broadcast(rwlock);
    rwlock->Release();
}



#endif
