#ifndef IBUTTON_H
#define IBUTTON_H

#include <vector>
#include <stdint.h>
#include "StateManager.h"

class StateManager;

class IButton
{
public:
	IButton(StateManager* sm) 
	{
		this->statemanager = sm;
	}
	virtual void Init() = 0;
	virtual void GetPressedButtons() = 0;
	
protected:
	StateManager* statemanager;
};

#endif
