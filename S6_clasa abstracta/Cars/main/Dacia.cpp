#include "Dacia.h"
#include <string.h>
Dacia::Dacia()
{
	strcpy(this->name, "Dacia");
	this->capacity = 1000;
	this->consum = 5;
	this->speed[0] = 100;
	this->speed[1] = 90;
	this->speed[2] = 80;
}

int Dacia::getCapacity()
{
	return this->capacity;
}

int Dacia::getConsum()
{
	return this->consum;
}

int Dacia::getSpeed(Weather a)
{
	return this->speed[a];
}

char* Dacia::getName()
{
	return this->name;
}