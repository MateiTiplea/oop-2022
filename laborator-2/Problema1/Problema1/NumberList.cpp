#include "NumberList.h"
#include <stdio.h>

void NumberList::Init() {
    count = 0;
}

bool NumberList::Add(int x) {
    if (count == 10)
        return false;
    count++;
    numbers[count-1] = x;
    return true;
}

void NumberList::Sort() {
    bool sortat;
    do {
        sortat = true;
        for (int i=0;i<count-1;i++) {
            if (numbers[i] > numbers[i+1]) {
                int aux = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = aux;
                sortat = false;
            }
        }
    } while (!sortat);
}

void NumberList::Print() {
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}
