#include "StateManager.h"
#include "LedControl.h"
#include "ButtonControl.h"
#include <cstddef>

StateManager::StateManager()
{
  memoryLED = new LedControl(51);
  bc = new ButtonControl();
}

StateManager::~StateManager()
{
    delete memoryLED;
    memoryLED = NULL;
}

