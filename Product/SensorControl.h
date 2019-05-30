#ifndef SENSORCONTROL_H
#define SENSORCONTROL_H

#define PORT 0
#define BIT 0

#include <vector>
#include <stdint.h>
#include "ISensor.h"
#include "Events.h"

class SensorControl : public ISensor
{
public:
	SensorControl(StateManager* sm):ISensor(sm){}
	void Init();
	void GetData();
	
private:
	
};


#endif
