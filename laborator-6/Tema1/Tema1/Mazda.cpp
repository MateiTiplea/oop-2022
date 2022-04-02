#include "Mazda.h"

Mazda::Mazda() {
    name = new char[6];
    strcpy(name, "Mazda");
    name[5] = '\0';
    avgSpeed = 78;
    fuelCapacity = 40;
    fuelConsumption = 6.5;
}

int Mazda::GetSpeed() const {
    return this->avgSpeed;
}

char* Mazda::GetName() const {
    return this->name;
}

float Mazda::GetFuelCapacity() const {
    return this->fuelCapacity;
}

float Mazda::GetFuelConsumption() const {
    return this->fuelConsumption;
}

void Mazda::WeatherSet(Weather vreme) {
    this->vreme = vreme;
    if (this->vreme == Weather::Rain) {
        this->avgSpeed = 75;
    }
    if (this->vreme == Weather::Snow) {
        this->avgSpeed = 68;
    }
}
