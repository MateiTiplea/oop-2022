#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Weather.h"
#include <cstring>

class Car {
  protected:
    char *name;
    float fuelCapacity;// rezervor in litri
	float fuelConsumption;// consum in l/100km
    int avgSpeed;// viteza medie in kmh
    Weather vreme;

  public:
    virtual int GetSpeed() const =0;
    virtual char* GetName() const =0;
    virtual float GetFuelCapacity() const = 0;
    virtual float GetFuelConsumption() const = 0;
    virtual void WeatherSet(Weather vreme) = 0;
};