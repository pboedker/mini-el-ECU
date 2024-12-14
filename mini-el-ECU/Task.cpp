// Task.cpp
#include "Task.h"

Task::Task(unsigned long ulInitInterval) {
  ulInterval = ulInitInterval;
}

bool Task::Tick(unsigned long ulMillis) {
  if (ulTickOld = 0)
  {
    ulTickOld = ulMillis;
  }
  else
  {
    if (ulMillis > ulTickOld)
    {
      ulTickCnt += (ulMillis - ulTickOld);
      ulTickOld = ulMillis;
    }
    if (ulTickCnt > ulInterval)
    {
        ulTickCnt -= ulInterval;
      return true;
    }
  }
  return false;
}

