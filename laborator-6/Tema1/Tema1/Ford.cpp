#include "Ford.h"

Ford::Ford() {
    name = new char[5];
    strcpy(name,"Ford");
    name[4] = '\0';
    avgSpeed = 92;
    fuelCapacity = 50;
    fuelConsumption = 9.1;
}

int Ford::GetSpeed() const {
    return this->avgSpeed;
}

char* Ford::GetName() const {
    return this->name;
}

float Ford::GetFuelCapacity() const {
    return this->fuelCapacity;
}

float Ford::GetFuelConsumption() const {
    return fuelConsumption;
}

void Ford::WeatherSet(Weather vreme) {
    this->vreme = vreme;
    if (this->vreme == Weather::Rain) {
        this->avgSpeed = 90;
    }
    if (this->vreme == Weather::Snow) {
        this->avgSpeed = 85;
    }
}
