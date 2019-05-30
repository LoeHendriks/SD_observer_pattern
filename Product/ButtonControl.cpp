#include "ButtonControl.h"
#include <iostream>
#include <fstream>
#include <stdio.h>


void ButtonControl::Init()
{
	buttons.clear();
	timeBt = {"time", 3, 40, 30, 0, TIME_BUTTON_PRESSED}; //30 > 0
	buttons.push_back(timeBt);
	startBt = {"start", 2, 24, 1, 0, START_BUTTON_PRESSED};
	buttons.push_back(startBt);
	stopBt = {"stop", 2, 11, 2, 0, STOP_BUTTON_PRESSED};
	buttons.push_back(stopBt);
	w90Bt = {"90 watt", 2, 12, 3, 0, POWER_BUTTON_PRESSED_90W};
	buttons.push_back(w90Bt);
	w180Bt = {"180 watt", 2, 13, 4, 0, POWER_BUTTON_PRESSED_180W};
	buttons.push_back(w180Bt);
}

void ButtonControl::GetPressedButtons()
{
	uint32_t port0;
	uint32_t port1;
	uint32_t port2;
	
	
	std::ifstream devfs;
	devfs.open("gpio", std::ios::in);
	
	std::string buffer;
	if(devfs.is_open())
	{
		while(getline(devfs, buffer));

		std::cout << buffer << std::endl;
		sscanf(buffer.c_str(), "%d %d %d", &port0, &port1, &port2);
		
		
		std::cout << "Port 0 reg: " << port0 << std::endl;
		std::cout << "Port 2 reg: " << port2 << std::endl;
		
		for(uint32_t i = 0; i < buttons.size(); i++)
		{
			switch(buttons[i].reg)
			{
				case 0:
				{
					if(port0 & (1<<buttons[i].bit))
					{
						std::cout << "Button: " << buttons[i].buttonName << " pressed microwave edition xxl 2.0" << std::endl;
						statemanager->HandleEvent(buttons[i].ev);
					}
					break;
				}
				case 2:
				{
					if(port2 & (1<<buttons[i].bit))
					{
						std::cout << "Button: " << buttons[i].buttonName << " pressed" << std::endl;
						statemanager->HandleEvent(buttons[i].ev);
					}
					break;
				}
				default:
					std::cout << "error: default" << std::endl;
					break;
			}
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




