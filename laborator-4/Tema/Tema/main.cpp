#include "Sort.h"
#include <iostream>

int main() {
    Sort obj1(10, 1, 100);
    obj1.InsertSort();
    obj1.Print();

    Sort obj2;
    obj2.Print();

    int v[] = { 1, 2, 3, 4, 5, 6, 7 };
    Sort obj3(v, 7);
    obj3.Print();

    Sort obj4(6, 3, 8, 1, 6, 10, 4);
    obj4.BubbleSort();
    obj4.Print();

    char sir[] = "4,3,7,9,12";
    Sort obj5(sir);
    obj5.QuickSort();
    obj5.Print();

	return 0;
}