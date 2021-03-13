#include "Student.h"
#include <cstring>

void Student::initName(char s[100])
{
	strcpy(this->nume, s);
}

void Student::initMath(float value)
{
	if (!(1 <= value && value <= 10))
		return;
	this->nota.math = value;
}

void Student::initEng(float value)
{
	if (!(1 <= value && value <= 10))
		return;
	this->nota.eng = value;
}

void Student::initHist(float value)
{
	if (!(1 <= value && value <= 10))
		return;
	this->nota.hist = value;
}

float Student::average()
{
	return (this->nota.math + this->nota.eng + this->nota.hist) / 3;
}

float Student::getMath()
{
	return this->nota.math;
}

float Student::getEng()
{
	return this->nota.eng;
}

float Student::getHist()
{
	return this->nota.hist;
}

char* Student::getName()
{
	return this->nume;
}
