#ifndef IBUTTON_H
#define IBUTTON_H

#include <vector>
#include <stdint.h>


class IButton
{
public:
	IButton() {}
	virtual void Init() = 0;
	virtual std::vector<uint32_t> GetPressedButtons() = 0;
};


#endif
