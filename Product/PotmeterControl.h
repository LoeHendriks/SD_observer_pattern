#ifndef POTMETERCONTROL_H
#define POTMETERCONTROL_H

#include <vector>
#include <stdint.h>
#include "IPotmeter.h"
#include "Events.h"

#define TIMETABLE_SIZE 49

class PotmeterControl : public IPotmeter
{
public:
	PotmeterControl(StateManager* sm):IPotmeter(sm){}
	
	void Init();
	void GetData();
	
	long map(long x, long in_min, long in_max, long out_min, long out_max);
	uint32_t ConvertPotValue(uint32_t val);

private:
	uint32_t currentValue;
	
};


#endif
