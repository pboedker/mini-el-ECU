// Task.cpp
#include "Task.h"

Task::Task(unsigned int uiInitInterval) {
  uiInterval = uiInitInterval;
  uiTickCnt = 0;
  ulTickOld = 0;
}

bool Task::Tick(unsigned long ulTick) {  
  if (ulTickOld == 0) {
    ulTickOld = ulTick;
  }
  else {
    if (ulTick > ulTickOld) {
      uiTickCnt += (int)(ulTick - ulTickOld);
      ulTickOld = ulTick;
    }
    if (uiTickCnt > uiInterval) {
      uiTickCnt -= uiInterval;
      return true;
    }
  }
  
  return false; // Default return
}

