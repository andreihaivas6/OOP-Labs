#pragma once
#include "Car.h"
class Dacia : public Car
{
public:
	Dacia();
	int getCapacity();
	int getConsum();
	int getSpeed(Weather);
	char* getName();
};

