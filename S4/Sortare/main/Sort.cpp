#include "Sort.h"
#define _CRT_SECURE_NO_WARNINGS
#include <time.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <stdarg.h> // va_arg
#include <string.h>

void Sort::insereaza(int x)
{
	nod* p = new nod;
	p->info = x;
	p->urm = NULL;
	if (this->prim == NULL)
		this->prim = this->ultim = p;
	else
	{
		this->ultim->urm = p;
		this->ultim = p;
	}
}

Sort::Sort(int length, int min, int max): prim(NULL), ultim(NULL)
{
	srand(time(NULL));
	for (int i = 0; i < length; ++i)
	{
		int k = rand() % (max - min + 1); // lung interval
		insereaza(k + min);
	}
}

Sort::Sort(int n, int v[]): prim(NULL), ultim(NULL)
{
	for (int i = 0; i < n; ++i)
		insereaza(v[i]);
}

Sort::Sort(int count, ...): prim(NULL), ultim(NULL)
{
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
		insereaza(va_arg(args, int));
	va_end(args);
}

Sort::Sort(char s[100]) : prim(NULL), ultim(NULL)
{
	char* p;
	p = strtok(s, ",");
	while (p)
	{
		char aux[100];
		strcpy(aux, p);
		insereaza(atoi(aux));
		p = strtok(NULL, ",");
	}
}

void Sort::atribuie(int poz, int val)
{
	nod* p = prim;
	for (int i = 0; i < poz; i++)
		p = p->urm;
	p->info = val;
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < GetElementsCount(); i++)
	{
		int j = i - 1;
		int x = GetElementFromIndex(i);
		while (x < GetElementFromIndex(j) && j >= 0)
		{
			atribuie(j + 1, GetElementFromIndex(j));
			j--;
		}
		atribuie(j + 1, x);
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSort(0, GetElementsCount() - 1);
}

void Sort::QuickSort(int pr, int ul)
{
	if (pr < ul)
	{
		int piv = (pr + ul) / 2;
		Partitioneaza(pr, ul, piv);
		QuickSort(pr, piv - 1);
		QuickSort(piv + 1, ul);
	}
}

void Sort::Partitioneaza(int pr, int ul, int piv)
{
	int x = GetElementFromIndex(pr);
	int i = pr + 1;
	int j = ul;
	while (i <= j)
	{
		if (GetElementFromIndex(i) <= x)
			i++;
		if (GetElementFromIndex(j) >= x)
			j--;
		if ((i < j) && (GetElementFromIndex(i) >= x) && (GetElementFromIndex(j) <= x))
		{
			int aux = GetElementFromIndex(i);
			atribuie(i, GetElementFromIndex(j));
			atribuie(j, aux);
			i++;
			j--;
		}
	}
	piv = i - 1;
	atribuie(pr, GetElementFromIndex(piv));
	atribuie(piv, x);
}

void Sort::BubbleSort(bool ascendent)
{
	bool gasit;
	do {
		gasit = false;
		for(int i = 0; i < GetElementsCount() - 1; i++)
			if (GetElementFromIndex(i) > GetElementFromIndex(i + 1))
			{
				int aux = GetElementFromIndex(i);
				atribuie(i, GetElementFromIndex(i + 1));
				atribuie(i + 1, aux);
				gasit = true;
			}

	} while (gasit);
}

void Sort::Print()
{
	nod* p = this->prim;
	while (p)
	{
		printf("%d ", p->info);
		p = p->urm;
	}
	printf("\n");
}

int Sort::GetElementsCount()
{
	int count = 0;
	nod* p = this->prim;
	while (p)
	{
		count++;
		p = p->urm;
	}
	return count;
}

int Sort::GetElementFromIndex(int index)
{
	nod* p = this->prim;
	for (int i = 0; i < index; i++)
		p = p->urm;
	return p->info;
}