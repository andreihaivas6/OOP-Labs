// sumaElemFisier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
	FILE* in = fopen("in.txt", "r");
	FILE* cv = fopen("cv.txt", "w");
	int suma = 0;
	char s[100];
	while (fgets(s, 99, in))
	{
		int k = 0;
		for (int i = 0; i < strlen(s); i++)
			if (s[i] >= '0' && s[i] <= '9') // sa nu ia si \n de la final
				k = k * 10 + (s[i] - '0');

		suma += k;
	}
	printf("%d", suma);
	fclose(in);

	printf("\n%s", "Ana are mere");
	fprintf(cv, "%s", "ana are mere");
	fclose(cv);
	return 0;
}
