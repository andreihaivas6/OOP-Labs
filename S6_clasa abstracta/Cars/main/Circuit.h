#pragma once
#include "Car.h"

class Circuit
{
private:
	int length;
	Weather vreme;
	//Car** cars = new Car* [100];
	Car* cars[100];
	int nrCars;
public:
	Circuit();
	void SetLength(int);
	void SetWeather(Weather);
	void AddCar(Car*);
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void SortSpeed();
};

