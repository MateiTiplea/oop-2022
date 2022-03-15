#pragma once

class Sort

{
    // add data members
    int* vect;
    int count;
    void Sorteaza(int* vect, int low, int high,bool ascendent);
    int Partitioneaza(int* vect, int low, int high,bool ascendent);

  public:
    // add constuctors
    Sort(int number, int v_min, int v_max);
    Sort();
    Sort(int v[], int n);
    Sort(int count, ...);
    Sort(char* sir);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int GetElementsCount();

    int GetElementFromIndex(int index);
};
