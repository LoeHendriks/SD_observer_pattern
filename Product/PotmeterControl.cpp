#include "PotmeterControl.h"
#include <iostream>
#include <fstream>
#include <stdio.h>



void PotmeterControl::Init()
{
	
}

void PotmeterControl::GetData()
{
	uint32_t potValue;
	uint32_t timeTable[TIMETABLE_SIZE+1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 75, 90, 105, 120, 135, 150, 165, 180, 195, 210, 225, 240, 300, 360, 420, 480, 540, 600, 720, 840, 960, 1080, 1200, 1500, 1800, 2100, 2400, 2700, 3000, 3300};
	std::ifstream devfs;
	devfs.open("adc2", std::ios::in);
	
	std::string buffer;
	if(devfs.is_open())
	{
		while(getline(devfs, buffer));

		std::cout << "retrieved buffer: " << buffer << std::endl;
		sscanf(buffer.c_str(), "%d", &potValue);
		std::cout << "Before map the potvalue is: " << potValue << std::endl;
		potValue = map(potValue, 0, 1023, 0, TIMETABLE_SIZE);
		std::cout << "After map the potvalue is: " << potValue << std::endl;
		if(potValue != currentValue)
		{
			std::cout << "updating statemanager" << std::endl;
			statemanager->UpdateClock(timeTable[potValue], TIME_DIALED);
			currentValue = potValue;
		}
	}
	else{
		std::cout << "file could not be opened" << std::endl;
	}
	
	if(devfs.is_open())
	{
		std::cout << "closing file" << std::endl;
		devfs.close();
		std::cout << "after closing file" << std::endl;
	}
}

uint32_t PotmeterControl::ConvertPotValue(uint32_t val)
{
	uint32_t timeTable[TIMETABLE_SIZE+1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 75, 90, 105, 120, 135, 150, 165, 180, 195, 210, 225, 240, 300, 360, 420, 480, 540, 600, 720, 840, 960, 1080, 1200, 1500, 1800, 2100, 2400, 2700, 3000, 3300};
	uint32_t result = map(val, 0, 1023, 0, TIMETABLE_SIZE);
	return timeTable[result];
}

long PotmeterControl::map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
