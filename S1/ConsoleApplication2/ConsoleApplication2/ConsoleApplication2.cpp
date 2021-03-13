#include <stdio.h> 
//#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char s[256], * p, aux[256], cuvinte[50][256];
	int i, nr_cuv = 0;
	//gets_s(s); -> mai bine
	fgets(s, 99, stdin);
	p = strtok(s, " ");
	while (p) {
		strcpy(cuvinte[nr_cuv], p);
		strcpy(aux, p);
		nr_cuv++;
		p = strtok(NULL, " ");
	}
	bool gasit;
	do {
		gasit = false;
		for (i = 0; i < nr_cuv - 1; i++)
			if((strlen(cuvinte[i]) < strlen(cuvinte[i + 1]) || 
			(strlen(cuvinte[i]) == strlen(cuvinte[i + 1]) && strcmp(cuvinte[i], cuvinte[i + 1]) < 0))){ // egale ca lungime
				gasit = true;
				strcpy(aux, cuvinte[i]);
				strcpy(cuvinte[i], cuvinte[i + 1]);
				strcpy(cuvinte[i + 1], aux);
			}
	} while (gasit);
	for (i = 0; i < nr_cuv; ++i) {
		 printf("%s \n", cuvinte[i]);
	}
	return 0;
}

