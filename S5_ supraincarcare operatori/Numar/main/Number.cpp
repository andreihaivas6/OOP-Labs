#define _CRT_SECURE_NO_WARNINGS

#include "Number.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

Number::Number() : number(""), base(0) { ; }

Number::Number(int value) : base(10)
{
	_itoa(value, this->number, 10);
}

Number::Number(const char* value, int base)
{
	strcpy(this->number, value);
	this->base = base;
}

Number::~Number() { ; }

void Number::Print()
{
	printf("Numarul este %s si este in baza %d\n", this->number, this->base);
}

int Number::GetDigitsCount()
{
	return strlen(this->number);
}

int Number::GetBase()
{
	return this->base;
}

int convToInt(char s)
{
	if (s >= '0' && s <= '9')
		return s - '0';
	else
		return s - 'a' + 10;
}

int atoi_10(char s[100], int baza)
{
	int nr = 0;
	int p = 1;
	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		nr += convToInt(s[i]) * p;
		p *= baza;
	}
	return nr;
}


void Number::SwitchBase(int newbase)
{
	int numar = atoi_10(this->number, this->base);
	_itoa(numar, this->number, newbase);
	this->base = newbase;
}

Number::Number(const Number& d)
{
	strcpy(this->number, d.number);
	this->base = d.base;
	std::cout << "\n123456789\n";
}

Number::Number(Number&& d) 
{
	strcpy(this->number, d.number);
	this->base = d.base;
	strcpy(d.number, "\0");
	d.base = 0;
}

char Number::operator[](int index)
{
	return this->number[index];
}

Number& Number::operator=(const Number& d)
{
	strcpy(this->number, d.number);
	this->base = d.base;
	std::cout << "\n1234567890\n";
	return *this;
}

Number& Number::operator=(int value)
{
	_itoa(value, this->number, this->base);
	return *this;
}

Number& Number::operator=(const char* value)
{
	strcpy(this->number, value);
	return *this;
}

Number operator+(const Number& d1, const Number& d2)
{
	Number rez;
	int maxBase;
	if (d1.base > d2.base)
		maxBase = d1.base;
	else
		maxBase = d2.base;
	Number D1 = d1;
	Number D2 = d2;
	D1.SwitchBase(10);
	D2.SwitchBase(10);
	int Rez = atoi(D1.number) + atoi(D2.number);
	_itoa(Rez, rez.number, maxBase);
	rez.base = maxBase;
	return rez;
}

Number& Number::operator+=(const Number& d)
{
	*this = (*this) + d;
	return *this;
}


Number operator-(const Number& d1, const Number& d2)
{
	Number rez;
	int maxBase;
	if (d1.base > d2.base)
		maxBase = d1.base;
	else
		maxBase = d2.base;
	Number D1 = d1;
	Number D2 = d2;
	D1.SwitchBase(10);
	D2.SwitchBase(10);
	int Rez = atoi(D1.number) - atoi(D2.number);
	_itoa(Rez, rez.number, maxBase);
	rez.base = maxBase;
	return rez;
}

Number Number::operator!()
{
	Number d = *this;
	d.SwitchBase(2);
	for (int i = 0; i < strlen(d.number); i++)
		d.number[i] = '1' - d.number[i] + '0';   // neg bitii
	char* p = strchr(d.number, '1');	//scapam de bitii de 0 din fata
	strcpy(d.number, p);
	d.SwitchBase(this->base);
	return d;
}

bool Number::operator>(const Number& d) // la fel si pt < >= <= == != 
{
	Number d1 = *this;
	Number d2 = d;
	d1.SwitchBase(10);
	d2.SwitchBase(10);
	if (atoi(d1.number) > atoi(d2.number))	// strcmp(d1.number, d2.number) > 0
		return true;
	return false;
}

Number& Number::operator--()
{
	strcpy(this->number, this->number + 1);
	return *this;
}

Number Number::operator--(int value) // value = 0 (mereu)
{
	printf("\n\n%d\n\n", value);
	Number d = *this;
	this->number[strlen(this->number) - 1] = '\0';
	return d;
}
