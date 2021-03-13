#pragma once
#include "Car.h"
class Toyota : public Car
{
public:
	Toyota();
	int getCapacity();
	int getConsum();
	int getSpeed(Weather);
	char* getName();
};

