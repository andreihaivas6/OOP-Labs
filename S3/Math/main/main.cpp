
#include <stdio.h>
#include <iostream>

#include "Math.h"

int main()
{
	//Math x();
	//printf("%d\n", x.Add(1, 2));
	printf("%d\n", Math::Add(1, 2, 3));
	printf("%d\n", Math::Add(1.2, 2.9));
	printf("%d\n", Math::Add(1.0, 2.7, 3.5));

	printf("%d\n", Math::Mul(1, 2));
	printf("%d\n", Math::Mul(1, 2, 3));
	printf("%d\n", Math::Mul(1.2, 2.9));
	printf("%d\n", Math::Mul(1.0, 2.7, 3.5));

	int a[] = { 1, 2, 3, 4, 5 };
	printf("%d \n", Math::Add(5, a));

	printf("%s \n", Math::Add("Ana", ""));
	printf("%s \n", Math::Add("Ana", " are mere"));
	return 0;
}