#ifndef IPOTMETER_H
#define IPOTMETER_H

#include <vector>
#include <stdint.h>
#include "StateManager.h"

class StateManager;

class IPotmeter
{
public:
	IPotmeter(StateManager* sm) 
	{
		this->statemanager = sm;
	}
	virtual void Init() = 0;
	virtual void GetData() = 0;
	
protected:
	StateManager* statemanager;
};


#endif
