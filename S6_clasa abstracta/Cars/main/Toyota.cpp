#include "Toyota.h"
#include <string.h>
Toyota::Toyota()
{
	strcpy(this->name, "Toyota");
	this->capacity = 1100;
	this->consum = 6;
	this->speed[0] = 110;
	this->speed[1] = 85;
	this->speed[2] = 70;
}

int Toyota::getCapacity()
{
	return this->capacity;
}

int Toyota::getConsum()
{
	return this->consum;
}

int Toyota::getSpeed(Weather a)
{
	return this->speed[(int)a];
}

char* Toyota::getName()
{
	return this->name;
}