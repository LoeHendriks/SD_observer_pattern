#include "StateManager.h"
#include "LedControl.h"
#include "ButtonControl.h"
#include "SensorControl.h"
#include "PotmeterControl.h"
#include <cstddef>
#include <iostream>
#include <unistd.h>

StateManager::StateManager()
{
  memoryLED = new LedControl(51);
  bc = new ButtonControl(this);
  bc->Init();
  doorSensor = new SensorControl(this);
  pot = new PotmeterControl(this);
  ispolling  = true;
}

StateManager::~StateManager()
{
    delete memoryLED;
    memoryLED = NULL;
}

void StateManager::HandleEvent(Event ev)
{
	std::cout << "Event handled: " << ev << std::endl;
}

void StateManager::StopPolling()
{
	ispolling = false;
}

void StateManager::PollButtonState()
{
	while(ispolling)
	{
		bc->GetPressedButtons();
		doorSensor->GetData();
		pot->GetData();
		usleep(100000);
	}
}


void StateManager::UpdateClock(uint32_t sec, Event ev)
{
	std::cout << "Updated clock to: " << sec << " seconds" << std::endl;
	std::cout << "Event handled: " << ev << std::endl;
	
	int total = sec;
	int seconds, hours, minutes;

	minutes = total / 60;
	seconds = total % 60;
	
	std::cout <<  "Set Display to: " << minutes << ":" << seconds << "0" << std::endl;
	CountDown(seconds, minutes);
}


//TODO(loehen): Must run on different thread and must be able to be canceled.
void StateManager::CountDown(uint32_t sec, uint32_t min)
{
	
	std::cout << "check" << std::endl;
	while(min != 0)
	{
		while(sec != 0)
		{
			std::cout << min << ":" << sec  << std::endl;
			sec--;
			usleep(1000000);
		}
		std::cout << min << ":" << sec  << std::endl;
		min--;
		sec = 59;
	}
	while(sec != 0)
	{
		std::cout << min << ":" << sec  << std::endl;
		sec--;
		usleep(1000000);
	}
}
