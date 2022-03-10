#include "Math.h"
#include <cstdio>

int main() {
    Math exemplu;
    printf("%d \n", exemplu.Add(1, 2));
    printf("%d \n", exemplu.Add(1, 2, 3));
    printf("%d \n", exemplu.Add(1.2, 2.4));
    printf("%d \n", exemplu.Add(1.3, 2.4, 3.7));
    printf("%d \n", exemplu.Mul(2, 2));
    printf("%d \n", exemplu.Mul(2, 2, 3));
    printf("%d \n", exemplu.Mul(2.4, 3.7));
    printf("%d \n", exemplu.Mul(2.4, 3.7, 4.5));
    printf("%d \n", exemplu.Add(5, 1, 2, 3, 4, 5));
    printf("%s \n", exemplu.Add("mare ", "saf"));
    return 0;
}