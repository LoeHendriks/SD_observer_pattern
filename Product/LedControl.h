#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include "ILED.h"

class LedControl : public ILED
{
public: 
	LedControl(uint32_t pin);
	~LedControl();
    void Init();
    void SetHigh();
    void SetLow();
    
    void SetLed(uint32_t highLow);
protected:
	uint32_t mPin;	

};

#endif
