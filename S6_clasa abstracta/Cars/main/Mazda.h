#pragma once
#include "Car.h"
class Mazda : public Car
{
public:
	Mazda();
	int getCapacity();
	int getConsum();
	int getSpeed(Weather);
	char* getName();
};
