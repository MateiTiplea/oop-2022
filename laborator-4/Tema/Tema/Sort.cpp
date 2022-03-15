#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <cstdarg>

Sort::Sort(int number, int v_min, int v_max) {
    this->count = number;
    vect = new int[count];
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        vect[i] = v_min + rand() % (v_max - v_min + 1);
    }
}

Sort::Sort() : vect(new int[5]{ 4, 7, 3, 8, 2 }) {
    count = 5;
}

Sort::Sort(int v[], int n) {
    vect = new int[n];
    for (int i = 0; i < n; i++) {
        vect[i] = v[i];
    }
    count = n;
}

Sort::Sort(int count, ...) {
    va_list args;
    va_start(args, count);
    this->count = count;
    vect = new int[count];
    for (int i = 0; i < count; i++) {
        vect[i] = va_arg(args, int);
    }
    va_end(args);
}

Sort::Sort(char* sir) {
    char* p;
    char elem[100][100];
    p = strtok(sir, ",");
    while (p != NULL) {
        strcpy(elem[count++], p);
        p = strtok(NULL, ",");
    }
    vect = new int[count];
    for (int i = 0; i < count; i++) {
        vect[i] = atoi(elem[i]);
    }
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < count; i++) {
        int j = i - 1;
        int temp = vect[i];
        if (ascendent == true) {
            while (j >= 0 && vect[j] > temp) {
                vect[j + 1] = vect[j];
                j--;
            }
        } else {
            while (j >= 0 && vect[j] < temp) {
                vect[j + 1] = vect[j];
                j--;
            }
        }
        if (vect[j + 1] != temp)
            vect[j + 1] = temp;
    }
}

void Sort::QuickSort(bool ascendent) {
    Sorteaza(vect, 0, count - 1, ascendent);
}

void Sort::Sorteaza(int* vect, int low, int high, bool ascendent) {
    if (low < high) {
        int pi = Partitioneaza(vect, low, high, ascendent);
        Sorteaza(vect, low, pi - 1, ascendent);
        Sorteaza(vect, pi + 1, high, ascendent);
    }
}

int Sort::Partitioneaza(int* vect, int low, int high, bool ascendent) {
    int x = vect[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        if (ascendent == true) {
            if (vect[i] <= x)
                i++;
            if (vect[j] >= x)
                j--;
            if (i < j && vect[i] > x && vect[j] < x) {
                vect[i] ^= vect[j] ^= vect[i] ^= vect[j];
                i++;
                j--;
            }
        } else {
            if (vect[i] >= x)
                i++;
            if (vect[j] <= x)
                j--;
            if (i < j && vect[i] < x && vect[j] > x) {
                vect[i] ^= vect[j] ^= vect[i] ^= vect[j];
                i++;
                j--;
            }
        }
    }
    vect[low] = vect[i - 1];
    vect[i - 1] = x;
    return i - 1;
}

void Sort::BubbleSort(bool ascendent) {
    int ultim = count - 1;
    while (ultim > 0) {
        int n1 = ultim - 1;
        ultim = 0;
        for (int i = 0; i <= n1; i++) {
            if (vect[i] > vect[i + 1] && ascendent == true) {
                vect[i] ^= vect[i + 1] ^= vect[i] ^= vect[i + 1];
                ultim = i;
            }
            if (vect[i] < vect[i + 1] && ascendent == false) {
                vect[i] ^= vect[i + 1] ^= vect[i] ^= vect[i + 1];
                ultim = i;
            }
        }
    }
}

void Sort::Print() {
    for (int i = 0; i < GetElementsCount(); i++)
        printf("%d ", GetElementFromIndex(i));
    printf("\n");
}

int Sort::GetElementsCount() {
    return this->count;
}

int Sort::GetElementFromIndex(int index) {
    return vect[index];
}
