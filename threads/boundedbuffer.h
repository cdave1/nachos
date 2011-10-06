
// Header file for BoundedBuffer.cc (see that file
// for documentation).

#include "list.h"
#include "synch.h"

class BoundedBuffer {
  public:
    BoundedBuffer(int c);	
    ~BoundedBuffer();

    void Append(char *item);
    char *Take();

  private:
    char* buffer;
    int in, out;
    int capacity;      // capacity of the bounded buffer.
    int itemCount;     // total items in the bounded buffer
    int inCS;          // count of items in critical section (should be 0 or 1)
    Lock *mutex;
    Condition *empty;  // wait in Remove if the list is empty
    Condition *full;   // wait in Append if the list is FULL.
};
