#include "Ford.h"
#include <string.h>
Ford::Ford()
{
	strcpy(this->name, "Ford");
	this->capacity = 900;
	this->consum = 6;
	this->speed[0] = 90;
	this->speed[1] = 80;
	this->speed[2] = 70;
}

int Ford::getCapacity()
{
	return this->capacity;
}

int Ford::getConsum()
{
	return this->consum;
}

int Ford::getSpeed(Weather a)
{
	return this->speed[(int)a];
}

char* Ford::getName()
{
	return this->name;
}