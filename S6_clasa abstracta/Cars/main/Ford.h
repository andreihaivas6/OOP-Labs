#pragma once
#include "Car.h"
class Ford : public Car
{
public:
	Ford();
	int getCapacity();
	int getConsum();
	int getSpeed(Weather);
	char* getName();
};

