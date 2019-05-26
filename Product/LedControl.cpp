#include "LedControl.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define LOW 0
#define HIGH 1

LedControl::LedControl(uint32_t pin)
{
	mPin = pin;
	Init();
}

void LedControl::Init()
{
	std::cout << "pin: " << mPin << std::endl;
	std::fstream sysfs;
    sysfs.open("sys/kernel/es6/data", std::ios::out);
    
	std::stringstream ss;
	ss << "1 " << mPin << " 1";

	std::string memString = ss.str();
	std::cout << "string: " << memString << std::endl;
	if(sysfs.is_open())
	{
		sysfs << memString;
	}
	else{
		std::cout << "file could not be opened" << std::endl;
	}
	sysfs.close();
}

void LedControl::SetHigh()
{
	SetLed(HIGH);

}

void LedControl::SetLow()
{
	SetLed(LOW);
}

void LedControl::SetLed(uint32_t highLow)
{
	if(highLow != 1 && highLow != 0)
	{
		std::cout << "Error: led can only be set to 1 or 0" << std::endl;
		return;
	}
	
	std::fstream devfs;
	devfs.open("gpio", std::ios::out);
	std::stringstream ss;
	ss << "1 " << mPin << " " << highLow;
	std::string memString = ss.str();
	std::cout << "string: " << memString << std::endl;
	if(devfs.is_open())
	{
		devfs << memString;
	}
	else{
		std::cout << "file could not be opened" << std::endl;
	}
	devfs.close();
}

