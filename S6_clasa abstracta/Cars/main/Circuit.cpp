#include "Circuit.h"
#include <stdio.h>
#include <algorithm>
Circuit::Circuit() : nrCars(0) {}

void Circuit::SetLength(int l)
{
	this->length = l;
}

void Circuit::SetWeather(Weather x)
{
	this->vreme = x;
}

void Circuit::AddCar(Car* c)
{
	this->cars[this->nrCars++] = c;
}

void Circuit::SortSpeed() // functia race()
{
	bool gasit;
	do{
		gasit = false;
		for (int i = 0; i < this->nrCars - 1; i++)
			if (this->cars[i]->getSpeed(this->vreme) < this->cars[i + 1]->getSpeed(this->vreme))
			{
				Car* aux = this->cars[i];
				this->cars[i] = this->cars[i + 1];
				this->cars[i + 1] = aux;
				gasit = true;
			}
	} while (gasit);
}

void Circuit::ShowFinalRanks()
{
	this->SortSpeed();
	for (int i = 0; i < this->nrCars; i++)
		printf("Masina %s termina circuitul in %f\n", this->cars[i]->getName(),
			(float)this->length / this->cars[i]->getSpeed(this->vreme));
}

void Circuit::ShowWhoDidNotFinish()
{
	printf("\n");
	for (int i = 0; i < this->nrCars; i++)
		if (this->cars[i]->getCapacity() / this->cars[i]->getConsum() < this->length)
			printf("Masina %s nu termina traseul\n", this->cars[i]->getName());
}