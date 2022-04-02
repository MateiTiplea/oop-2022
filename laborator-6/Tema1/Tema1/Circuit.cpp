#include "Circuit.h"
#include <stdio.h>

Circuit::Circuit() {
    car_number = 0;
    finish_cars_number = 0;
    not_finish_car_number = 0;
    vreme = Weather::Sunny;
    Length = 0;
}

void Circuit::SetWeather(Weather vreme) {
    this->vreme = vreme;
    for (int i = 0; i < car_number; i++)
    {
        cars[i]->WeatherSet(vreme);
    }
}

void Circuit::SetLength(int Length) {
    this->Length = Length;
}

void Circuit::AddCar(Car* obj) {
    obj->WeatherSet(this->vreme);
    cars[car_number] = obj;
    this->car_number++;
}

void Circuit::Race() {
    for (int i=0;i<car_number;i++) {
        int distance_car = (int) (cars[i]->GetFuelCapacity() / cars[i]->GetFuelConsumption()) * 100 * 1000;
        if (distance_car < Length) {
            not_finish_cars[not_finish_car_number] = cars[i];
            not_finish_car_number++;
        } else {
            finish_cars[finish_cars_number] = cars[i];
            int j = finish_cars_number;
            while (j>0) {
                if (FinishTime(finish_cars[j]->GetSpeed()) < FinishTime(finish_cars[j - 1]->GetSpeed())) {
                    Car* aux = finish_cars[j];
                    finish_cars[j] = finish_cars[j - 1];
                    finish_cars[j - 1] = aux;
                } else
                    break;
                j--;
            }
            finish_cars_number++;

        }
    }
}

void Circuit::ShowFinalRanks() {
    if (finish_cars_number==0) {
        printf("No car finished the race");
    } else {
        for (int i=0;i<finish_cars_number;i++) {
            double time = FinishTime(finish_cars[i]->GetSpeed());
            int sec_time = (int)(time * 3600);
            int sec = sec_time % 60;
            int min_total = sec_time / 60;
            int min = min_total % 60;
            int h = min_total / 60;
            /*
            int h = int(time);
            double min_sec = time - h;
            min_sec *= 60;
            int min = (int)min_sec;
            double sec = min_sec - min;
            int secunde = (int) sec * 60;*/
            printf("%s : %02dh:%02dm:%02ds \n", finish_cars[i]->GetName(),
                h,min,sec);
        }
    }
    printf("\n");
}

void Circuit::ShowWhoDidNotFinish() {
    if (not_finish_car_number == 0)
        printf("Every car finished the race\n");
    else {
        for (int i = 0; i < not_finish_car_number; i++) {
            printf(
                  "%s did not finish the race \n",
                  not_finish_cars[i]->GetName());
        }
    }
}

double Circuit::FinishTime(int speed) const {
    return (double)(Length*1.00/1000)/speed;
}

