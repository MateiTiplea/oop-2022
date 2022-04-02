#include "Toyota.h"

Toyota::Toyota() {
    name = new char[7];
    strcpy(name, "Toyota");
    name[6] = '\0';
    avgSpeed = 68;
    fuelCapacity = 54;
    fuelConsumption = 4.5;
}

int Toyota::GetSpeed() const {
    return this->avgSpeed;
}

char* Toyota::GetName() const {
    return this->name;
}

float Toyota::GetFuelCapacity() const {
    return this->fuelCapacity;
}

float Toyota::GetFuelConsumption() const {
    return this->fuelConsumption;
}

void Toyota::WeatherSet(Weather vreme) {
    this->vreme = vreme;
    if (this->vreme == Weather::Rain) {
        this->avgSpeed = 64;
    }
    if (this->vreme == Weather::Snow) {
        this->avgSpeed = 60;
    }
}
