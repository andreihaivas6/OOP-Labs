#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ... )
{
	int suma = 0;
	va_list arg;
	va_start(arg, count);
	int *x = (int *)va_arg(arg, int);
	for (int i = 0; i < count; ++i)
		suma += *(x + i);
	va_end(arg);
	return suma;
}

char* Math::Add(const char* a, const char* b)
{
	if (!a[0] || !b[0])
		return nullptr;
	char* s = (char*)malloc(strlen(a) + strlen(b));
	//char *s = new char[strlen(a) + strlen(b)];
	strcpy(s, a);
	strcat(s, b);
	return s;
}