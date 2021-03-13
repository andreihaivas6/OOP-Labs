#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Weather.h"
class Car
{
protected:
	int capacity, consum;
	int* speed = new int[3];
	char name[100];
public:
	virtual int getCapacity() = 0;
	virtual int getConsum() = 0;
	virtual int getSpeed(Weather x) = 0;
	virtual char* getName() = 0;
};
