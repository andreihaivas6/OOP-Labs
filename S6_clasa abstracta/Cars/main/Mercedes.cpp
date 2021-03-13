#include "Mercedes.h"
#include <string.h>
Mercedes::Mercedes()
{
	strcpy(this->name, "Mercedes");
	this->capacity = 1300;
	this->consum = 7;
	this->speed[0] = 120;
	this->speed[1] = 115;
	this->speed[2] = 90;
}

int Mercedes::getCapacity()
{
	return this->capacity;
}

int Mercedes::getConsum()
{
	return this->consum;
}

int Mercedes::getSpeed(Weather a)
{
	return this->speed[(int)a];
}

char* Mercedes::getName()
{
	return this->name;
}