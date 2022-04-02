#include "Dacia.h"

Dacia::Dacia()
{
    name = new char[6];
    strcpy(name, "Dacia");
    name[5] = '\0';
    fuelCapacity = 45.0;
    fuelConsumption = 7.2;
    avgSpeed = 50;
}

int Dacia::GetSpeed() const {
    return this->avgSpeed;
}

char* Dacia::GetName() const {
    return  this->name;
}

float Dacia::GetFuelCapacity() const {
    return this->fuelCapacity;
}

float Dacia::GetFuelConsumption() const {
    return this->fuelConsumption;
}

void Dacia::WeatherSet(Weather vreme) {
    this->vreme = vreme;
    if (this->vreme == Weather::Rain) {
        this->avgSpeed = 47;
    }
    if (this->vreme == Weather::Snow) {
        this->avgSpeed = 40;
    }
}
