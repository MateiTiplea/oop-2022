#pragma once
#include "Car.h"

class Mercedes : public Car {
  public:
    Mercedes();
    int GetSpeed() const;
    char* GetName() const;
    float GetFuelCapacity() const;
    float GetFuelConsumption() const;
    void WeatherSet(Weather vreme);
};