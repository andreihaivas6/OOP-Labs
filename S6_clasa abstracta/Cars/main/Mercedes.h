#pragma once
#include "Car.h"
class Mercedes : public Car
{
public:
	Mercedes();
	int getCapacity();
	int getConsum();
	int getSpeed(Weather);
	char* getName();
};
