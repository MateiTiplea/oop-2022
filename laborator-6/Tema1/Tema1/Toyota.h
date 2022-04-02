#pragma once
#include "Car.h"

class Toyota : public Car {
  public:
    Toyota();
    int GetSpeed() const;
    char* GetName() const;
    float GetFuelCapacity() const;
    float GetFuelConsumption() const;
    void WeatherSet(Weather vreme);
};