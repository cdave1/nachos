// David Petrie
//
// Producer consumer handler.
#ifdef CHANGED
#include <iostream>
#include "system.h"
#include "boundedbuffer.h"
#include "synch.h"
#include "unistd.h"


BoundedBuffer *b;


// Producer appends the string to the
// buffer one character at a time.
void Producer(int which)
{
  char* hw = "Hello World";

  while (*hw != '\0') {
    char *c = new char;
    *c = *hw++;
    b->Append(c);
    currentThread->Yield();
  }
}


// Consumer consumers items from the buffer.
void Consumer(int which)
{
    int num;
    char *c;
    
    for (num = 0; num < 15; num++) {
      c=(char *)b->Take();
      currentThread->Yield();
    }
}


// main.cc calls this function.
//
// Initialises a set of Producer and
// Consumer threads...
void ProducerConsumer()
{
    DEBUG('t', "Entering Producer/Consumer\n");
    int maxProducers = 10;
    int maxConsumers = 10;
    char* name;

    b = new BoundedBuffer(10);
    
    Thread *producers[maxProducers];
    Thread *consumers[maxConsumers];

    for (int i = 0; i < maxProducers; i++)
    {     
      name = (char *)malloc(sizeof(char) * 16);
      sprintf(name, "Producer %d", i);
      producers[i] = new Thread(name);
      producers[i]->Fork(Producer, i);
    }

    for (int j = 0; j < maxConsumers; j++)
    {
      name = (char *)malloc(sizeof(char) * 16);
      sprintf(name, "Consumer %d", j);
      consumers[j] = new Thread(name);
      consumers[j]->Fork(Consumer, j);
    }
}
#endif
