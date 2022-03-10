#include "Math.h"
#include <cstdio>
#include <string.h>
#include <stdarg.h>

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return (int) a + b;
}

int Math::Add(double a, double b, double c) {
    return (int) a + b + c;
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

int Math::Mul(double a, double b) {
    return (int) a * b;
}

int Math::Mul(double a, double b, double c) {
    return (int) a * b * c;
}

int Math::Add(int count, ...) {
    int* p = &count;
    int x,sum=0;
    va_list args;
    va_start(args, count);
    for (unsigned i = 0; i < count; i++) {
        x = va_arg(args, int);
        sum += x;
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* a, const char* b) {
    int lungime,lungimeA;
    lungimeA = strlen(a);
    lungime = lungimeA + strlen(b)+1;
    char* p = new char[lungime];
    for (unsigned i = 0; a[i]; i++)
        *(p + i) = a[i];
    for (unsigned i = 0; b[i]; i++)
        *(p + lungimeA + i) = b[i];
    *(p + lungime-1) = '\0';
    return p;
}
