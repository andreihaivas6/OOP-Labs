#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Sort.h"

int main()
{
    Sort x1(5, 10, 20);
    x1.Print();
    printf("\n");

    int v[] = { 25, 10, 15, 5, 20 };
    Sort x2 = { 5, v };
    x2.Print();
    x2.InsertSort(true);
    x2.Print();
    printf("\n");

    Sort x3(5, 15, 42, 3, 17, 20);
    x3.Print();
    x3.BubbleSort(true);
    x3.Print();
    printf("\n");

    char s[100] = "42,8,28,20,50";
    Sort x4(s);
    x4.Print();
    x4.QuickSort(true);
    x4.Print();
    return 0;
}
