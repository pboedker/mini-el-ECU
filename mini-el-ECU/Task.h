// Task.h
#ifndef Task_h
#define Task_h

// TODO, delete? #include <Arduino.h>

class Task {
  private:
    unsigned int uiInterval;
    unsigned int uiTickCnt;
    unsigned long ulTickOld;
    
  public:
    Task(unsigned int uiInitInterval);
    bool Tick(unsigned long ulTick);
};

#endif

