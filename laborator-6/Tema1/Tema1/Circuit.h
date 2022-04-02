#pragma once
#include "Weather.h"
#include "Car.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Toyota.h"
#include "Dacia.h"
#include "Mazda.h"

class Circuit{
  private:
    Car* cars[10];
    unsigned car_number;//numarul de masini din cursa
    int finish_cars_number;//numarul de masini care termina cursa
    int not_finish_car_number;//nr de masini care nu termina cursa
    Car* finish_cars[10];
    Car* not_finish_cars[10];
    Weather vreme;
    int Length;// lungime in metri
  public:
    Circuit();
    void SetWeather(Weather vreme);
    void SetLength(int Length);
    void AddCar(Car *obj);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
    double FinishTime(int speed)const;
};