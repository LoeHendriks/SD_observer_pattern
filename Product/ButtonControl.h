#ifndef BUTTONCONTROL_H
#define BUTTONCONTROL_H

#include "IButton.h"
#include "Events.h"
#include <string>

#define BUTTON_TIME_PIN 40
#define BUTTON_TIME_J 3

#define BUTTON_START_PIN 24
#define BUTTON_START_J 2

#define BUTTON_STOP_PIN 11
#define BUTTON_STOP_J 2

#define BUTTON_90W_PIN 12
#define BUTTON_90W_J 2

#define BUTTON_180W_PIN 13
#define BUTTON_180W_J 2

#define BUTTON_360W_PIN 48 //error
#define BUTTON_360W_J 3

#define BUTTON_600W_PIN 33
#define BUTTON_600W_J 3

#define BUTTON_900W_PIN 27
#define BUTTON_900W_J 1

#define BUTTON_MEMORY_PIN 47
#define BUTTON_MEMORY_J 3
// TODO:: add remaining buttons


struct Button
{
	std::string buttonName;
	uint32_t jConnector;
	uint32_t pin;
	uint32_t bit;
	uint32_t reg;
	Event ev;
};

class ButtonControl : public IButton
{
public:
	ButtonControl(StateManager* sm):IButton(sm){}
	void Init();
	void GetPressedButtons();
private:
	Button timeBt;
	Button startBt;
	Button stopBt;
	Button w90Bt;
	Button w180Bt;
	Button w360Bt;
	Button w600Bt;
	Button w900Bt;
	Button memoryBt;
	std::vector<Button> buttons;
};

#endif
