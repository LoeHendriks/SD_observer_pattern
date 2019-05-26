#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "ILED.h"
#include "IButton.h"

class ILED;

class StateManager
{
public:
    StateManager();
    ~StateManager();
    
	ILED* memoryLED;
	ILED* ovenLED;
	
	IButton* bc;
};

#endif
