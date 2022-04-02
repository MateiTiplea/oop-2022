#include "Car.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Toyota.h"
#include "Dacia.h"
#include "Mazda.h"
#include "Circuit.h"
#include <iostream>

int main()
{
    Circuit c;
    c.SetLength(12004);
    c.SetWeather(Weather::Sunny);
    c.AddCar(new Dacia());
    c.AddCar(new Toyota());
    c.AddCar(new Mercedes());
    c.AddCar(new Ford());
    c.AddCar(new Mazda());
    c.Race();
    c.ShowFinalRanks();
    c.ShowWhoDidNotFinish();
	return 0;
}