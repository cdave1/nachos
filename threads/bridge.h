// David Petrie
//
// Header file for Bridge.cc (see that file for more)...

#include "list.h"
#include "synch.h"

class Bridge {
 public:
  Bridge(int max);
  ~Bridge();

  void ArriveBridge(int direction);
  void CrossBridge(int direction);
  void ExitBridge(int direction);

 private:
  Lock *mutex;
  Condition *full;
  int currDirection;
  int totalCars;
  int maxCars;
  int inCS;
};
