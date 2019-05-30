#ifndef ISENSOR_H
#define ISENSOR_H

#include <vector>
#include <stdint.h>
#include "StateManager.h"

class StateManager;

class ISensor
{
public:
	ISensor(StateManager* sm) 
	{
		this->statemanager = sm;
	}
	virtual void Init() = 0;
	virtual void GetData() = 0;
	
protected:
	StateManager* statemanager;
};


#endif
