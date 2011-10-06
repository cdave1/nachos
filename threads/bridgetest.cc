// David Petrie
//
// Bridge testing handler.
#include <iostream>
#include "system.h"
#include "bridge.h"
#include "synch.h"
#include "unistd.h"


Bridge *bridge;


// The car attempts to cross the bridge in repeatedly
// opposing directions.
void Car(int which)
{
  int direction;
  for (int i = 0; i < 60; i++)
  {
    direction = i % 2;

    bridge->ArriveBridge(direction);
    currentThread->Yield();
    bridge->CrossBridge(direction);
    currentThread->Yield();
    bridge->ExitBridge(direction);
    printf("Car %d has crossed the bridge in direction %d\n\n", which, direction);
    currentThread->Yield();
  }
}


// Initialises a bridge and a set of cars.
//
// Each car runs in a separate thread.
void BridgeTest()
{
  bridge = new Bridge(3);
  int maxCars = 20;
  char* name;
  Thread *cars[maxCars];

  for (int i = 0; i < maxCars; i++)
  {
    name = (char *)malloc(sizeof(char) * 8);
    sprintf(name, "Car %d", i);
    cars[i] = new Thread(name);
    cars[i]->Fork(Car, i);
  }  
}

