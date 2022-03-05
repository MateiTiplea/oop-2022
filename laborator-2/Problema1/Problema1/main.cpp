#include "NumberList.h"
#include <iostream>

int main() {
    NumberList lista;
    lista.Init();
    for (int i=11;i>=1;i--) {
        if (!lista.Add(i))
            printf("Nu mai este spatiu in vector !!!\n");
        lista.Print();
    }
    lista.Sort();
    lista.Print();
	return 0;
}