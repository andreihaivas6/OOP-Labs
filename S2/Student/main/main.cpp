// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

#include "Student.h"
#include "functions.h"

using namespace std;

int main()
{
	Student a, b;

	char s1[100] = "Ion", s2[100] = "Marcel";
	a.initName(s1);
	b.initName(s2);

	const float x[] = { 7.5, 8, 5, 7.4, 8, 9 };
	a.initMath(x[0]);
	a.initEng(x[1]);
	a.initHist(x[2]);

	b.initMath(x[3]);
	b.initEng(x[4]);
	b.initHist(x[5]);
	
	printf("%d \n", compName(a.getName(), b.getName()));
	printf("%d \n", compMath(a.getMath(), b.getMath()));
	printf("%d \n", compEng(a.getEng(), b.getEng()));
	printf("%d \n", compHist(a.getHist(), b.getHist()));
	printf("%d \n", compAverage(a.average(), b.average()));
	
	return 0;
}
