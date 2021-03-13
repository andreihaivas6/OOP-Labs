#include "Mazda.h"
#include <string.h>
Mazda::Mazda()
{
	strcpy(this->name, "Mazda");
	this->capacity = 800;
	this->consum = 6;
	this->speed[0] = 120;
	this->speed[1] = 110;
	this->speed[2] = 100;
}

int Mazda::getCapacity()
{
	return this->capacity;
}

int Mazda::getConsum()
{
	return this->consum;
}

int Mazda::getSpeed(Weather a)
{
	return this->speed[(int)a];
}

char* Mazda::getName()
{
	return this->name;
}