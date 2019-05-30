#include "SensorControl.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

bool isclosed = true;

void SensorControl::Init()
{
	
}

void SensorControl::GetData()
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
		
		if(port0 & (1<<BIT))
		{
			if(isclosed)
			{
				std::cout << "Door opened: " << std::endl;
				statemanager->HandleEvent(DOOR_OPENED);
				isclosed = false;
			}
		}
		else
		{
			if(!isclosed)
			{
				std::cout << "Door closed: " << std::endl;
				statemanager->HandleEvent(DOOR_CLOSED);
				isclosed = true;
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
