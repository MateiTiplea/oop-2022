#include "Mercedes.h"

Mercedes::Mercedes() {
    name = new char[9];
    strcpy(name,"Mercedes");
    name[8] = '\0';
    avgSpeed = 120;//viteza pe sunny
    fuelCapacity = 56;
    fuelConsumption = 6.8;
}

int Mercedes::GetSpeed() const {
    return this->avgSpeed;
}

char* Mercedes::GetName() const {
    return this->name;
}

float Mercedes::GetFuelCapacity() const {
    return this->fuelCapacity;
}

float Mercedes::GetFuelConsumption() const {
    return this->fuelConsumption;
}

void Mercedes::WeatherSet(Weather vreme) {
    this->vreme = vreme;
    if (this->vreme == Weather::Rain) {
        this->avgSpeed = 110;
    }
    if (this->vreme == Weather::Snow) {
        this->avgSpeed = 95;
    }
}
