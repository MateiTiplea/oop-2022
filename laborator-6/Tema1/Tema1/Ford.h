#pragma once
#include "Car.h"

class Ford : public Car {
  public:
    Ford();
    int GetSpeed() const;
    char* GetName() const;
    float GetFuelCapacity() const;
    float GetFuelConsumption() const;
    void WeatherSet(Weather vreme);
};