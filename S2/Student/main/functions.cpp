#include "functions.h"
#include <cstring>
#include "Student.h"

int compName(char s1[100], char s2[100])
{
	if (strcmp(s1, s2) > 0)
		return 1;
	else
		if (strcmp(s1 , s2) == 0)
			return 0;
		else
			return -1;
}

int compMath(float x, float y)
{
	if (x > y)
		return 1;
	else
		if (x == y)
			return 0;
		else
			return -1;
}
int compEng(float x, float y)
{
	if (x > y)
		return 1;
	else
		if (x == y)
			return 0;
		else
			return -1;
}
int compHist(float x, float y)
{
	if (x > y)
		return 1;
	else
		if (x == y)
			return 0;
		else
			return -1;
}

int compAverage(float x, float y)
{
	if (x > y)
		return 1;
	else
		if (x == y)
			return 0;
		else
			return -1;
}
