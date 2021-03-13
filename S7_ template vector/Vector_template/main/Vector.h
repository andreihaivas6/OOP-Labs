#pragma once
#include "Number.h"
#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class Vector
{
private:
	T* list;
	int count, size;
public:
	Vector();
	void push(T);
	T pop();
	void delete_(int);
	void insert(T, int);
	void sort(bool (*Greater)(T a, T b)); //cb
	const T& get(int);
	void set(T, int);
	int count_();
	int firstIndexOf(T, bool (*Equal)(T a, T b)); //cb

	void resize();
};

template <class T>
Vector <T>::Vector()
{
	this->list = nullptr;
	this->count = this->size = 0;
}
 
template <class T>
void Vector <T>::resize()
{
	if (this->size == 0)
		this->size = 1;
	else 
		this->size *= 2;
	T* aux = new T[this->size];

	for (int i = 0; i < this->count; i++) 
		aux[i] = this->list[i];
	//memcpy(aux, this->list, sizeof(T) * this->count);
	delete[] this->list;
	this->list = aux;
}

template <class T>
void Vector <T>::push(T x)
{
	if (this->count == this->size)
		this->resize();
	this->list[this->count++] = x;
}

template <class T>
T Vector <T>::pop()
{
	return this->list[this->count - 1];
}

template <class T>
void Vector <T>::delete_(int i)
{
	if (i >= this->count)
	{
		cout << "Eroare: Nu exista element de sters la acea pozitie \n";
		return;
	}

	for (int k = i; k < this->count - 1; k++)
		this->list[k] = this->list[k + 1];
	//memcpy(this->list + i, this->list + i + 1, sizeof(T) * (this->count - i - 1));
	this->count--;
}

template <class T>
void Vector <T>::insert(T x, int i)
{
	if (i > this->count)
	{
		cout << "Eroare: Nu este o pozitie la care poti insera \n";
		return;
	}
	if (this->count == this->size)
		this->resize();

	for (int k = this->count; k > i; k--)
		this->list[k] = this->list[k - 1];
	//memcpy(this->list + i + 1, this->list + i, sizeof(T) * (this->count - i));
	this->count++;
	this->list[i] = x;
}

template <class T>
void Vector <T>::sort(bool (*Greater)(T a, T b))
{
	bool gasit;
	if (Greater == nullptr)
		do {
			gasit = false;
			for (int i = 0; i < this->count - 1; i++)
				if (this->list[i] > this->list[i + 1])
				{
					gasit = true;
					T aux = this->list[i];
					this->list[i] = this->list[i + 1];
					this->list[i + 1] = aux;
				}
		} while (gasit);
	else
		do {
			gasit = false;
			for (int i = 0; i < this->count - 1; i++)
				if (Greater(this->list[i], this->list[i + 1]))
				{
					gasit = true;
					T aux = this->list[i];
					this->list[i] = this->list[i + 1];
					this->list[i + 1] = aux;
				}
		} while (gasit);
}

template <class T>
const T& Vector <T>::get(int i)
{
	return this->list[i];
}

template <class T>
void Vector <T>::set(T x, int i)
{
	if (i >= this->count)
	{
		cout << "Eroare: Nu este o pozitie la care poti seta un obiect \n";
		return;
	}
	this->list[i] = x;
}

template <class T>
int Vector <T>::count_()
{
	return this->count;
}

template <class T>
int Vector <T>::firstIndexOf(T x, bool (*Equal)(T a, T b))
{
	if (Equal == nullptr) {
		for (int i = 0; i < this->count; i++)
			if (x == this->list[i])
				return i;
	}
	else {
		for (int i = 0; i < this->count; i++)
			if (Equal(x, this->list[i]))
				return i;
	}
	cout << "Obiectul nu exista\n";
	return -1;
}

template <class T>
bool Greater(T a, T b)
{
	return a > b;
}

template <class T>
bool Equal(T a, T b)
{
	return a == b;
}