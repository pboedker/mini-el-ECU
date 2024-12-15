// Task.cpp
#include "Task.h"

Task::Task(unsigned long ulInitInterval) {
  ulInterval = ulInitInterval;
  ulTickCnt = 0;
}

bool Task::Tick(unsigned long ulTick) {
  if (ulTickOld == 0)
  {
    ulTickOld = ulTick;
  }
  else
  {
    if (ulTick > ulTickOld)
    {
      ulTickCnt += (ulTick - ulTickOld);
      ulTickOld = ulTick;
    }
    if (ulTickCnt > 1000) //ulInterval)
    {
      ulTickCnt -= ulInterval;
      return true;
    }
  }
  
  return false; // Default return
}

