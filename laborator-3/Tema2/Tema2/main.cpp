#include "Canvas.h"

int main() {
    Canvas picture(40, 40);
    picture.DrawCircle(20, 20, 10, '.');
    picture.Print();   
    picture.Clear();
    picture.FillCircle(20, 20, 15, '.');
    picture.Print();
    picture.Clear();
    picture.DrawRect(15, 10, 35, 30, '.');
    picture.Print();
    picture.Clear();
    picture.FillRect(15, 10, 35, 30, '.');
    picture.Print();
    picture.Clear();
    picture.DrawLine(10, 15, 25, 20, '.');
    picture.Print();
    picture.Clear();
    return 0;
}