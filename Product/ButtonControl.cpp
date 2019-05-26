#include "ButtonControl.h"
#include <iostream>
#include <fstream>
#include <stdio.h>


ButtonControl::ButtonControl()
{
	timeBt = {"time", 3, 40, 0, 0};
	buttons.push_back(timeBt);
	startBt = {"start", 2, 24, 1, 0};
	buttons.push_back(startBt);
	stopBt = {"start", 2, 11, 2, 0};
	buttons.push_back(stopBt);
	w90Bt = {"start", 2, 12, 3, 0};
	buttons.push_back(w90Bt);
	w180Bt = {"start", 2, 13, 4, 0};
	buttons.push_back(w180Bt);
	
	
}


void ButtonControl::Init()
{
	
}

std::vector<uint32_t> ButtonControl::GetPressedButtons()
{
	vector<uint32_t> buttonspressed;
	uint32_t port0;
	uint32_t port1;
	uint32_t port2;
	
	
	std::ifstream devfs;
	devfs.open("gpio", std::ios::in);
	
	std::string buffer;
	if(devfs.is_open())
	{
		getline(devfs, buffer);
		//while()
		//{
			std::cout << buffer << std::endl;
		//}
		sscanf(buffer.c_str(), "%d %d %d", &port0, &port1, &port2);
		
		
		std::cout << port0 << std::endl;
		std::cout << port1 << std::endl;
		std::cout << port2 << std::endl;
		
		for(uint32_t i = 0; i < buttons.size(); i++)
		{
			switch(buttons[i].reg)
			{
				case 0:
				{
					if(port0 & (1<<buttons[i].bit))
					{
						std::cout << "Button: " << buttons[i].buttonName << " pressed" << std::endl;
						
					}
				}
			}
		}
		devfs.close();
	}
	else{
		std::cout << "file could not be opened" << std::endl;
	}
}




