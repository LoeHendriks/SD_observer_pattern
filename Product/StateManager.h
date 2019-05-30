#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "ILED.h"
#include "IButton.h"
#include "Events.h"
#include "ISensor.h"
#include "IPotmeter.h"

class ILED;
class IButton;
class ISensor;
class IPotmeter;

class StateManager
{
public:
    StateManager();
    ~StateManager();
    
    void HandleEvent(Event ev);
    void StopPolling();
    void PollButtonState();
    void UpdateClock(uint32_t sec, Event ev);
    void CountDown(uint32_t sec, uint32_t min);
    
	ILED* memoryLED;
	ILED* ovenLED;
	
	IButton* bc;
	IPotmeter* pot;
	
	ISensor* doorSensor;
	
private:
	bool ispolling;

};


#endif
