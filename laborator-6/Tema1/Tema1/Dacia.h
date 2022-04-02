#pragma once
#include "Car.h"

class Dacia : public Car {
  public:
    Dacia();
    int GetSpeed() const;
    char* GetName() const;
    float GetFuelCapacity() const;
    float GetFuelConsumption() const;
    void WeatherSet(Weather vreme);
};