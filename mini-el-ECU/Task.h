// Task.h
#ifndef Task_h
#define Task_h

#include <Arduino.h>

class Task {
  private:
    unsigned long ulInterval;
    unsigned long ulTickOld, ulTickCnt;

  public:
    Task(unsigned long ulInitInterval);
    bool Tick(unsigned long ulMillis);
};

#endif
