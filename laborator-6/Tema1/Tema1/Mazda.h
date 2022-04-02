#pragma once
#include "Car.h"

class Mazda : public Car {
  public:
    Mazda();
    int GetSpeed() const;
    char* GetName() const;
    float GetFuelCapacity() const;
    float GetFuelConsumption() const;
    void WeatherSet(Weather vreme);
};