#ifndef ILED_H
#define ILED_H

#include <stdint.h>
#include "StateManager.h"

class StateManager;

class ILED{
public:
    ILED() {}    
    virtual void Init() = 0;
    virtual void SetHigh() = 0;
    virtual void SetLow() = 0;

};


#endif
