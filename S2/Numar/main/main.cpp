// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "NumberList.h"
#include <stdio.h>
#include "NumberList.h"

using namespace std;

int main()
{
	NumberList x;

	x.Init();
	for (int i = 15; i >= 10; --i)
		x.Add(i);
	x.Add(5);
	x.Sort();
	x.Print();

	return 0;
}