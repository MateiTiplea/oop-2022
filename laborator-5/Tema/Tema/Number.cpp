#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <cstdio>
#include <cmath>

int Number::toDec() const {
    int power = 1;
    int num = 0;
    for (int i = this->nr_digits - 1; i >= 0; i--) {
        int digit;
        if (this->value[i] >= '0' && this->value[i] <= '9')
            digit = (int) this->value[i] - '0';
        else
            digit = (int) this->value[i] - 'A' + 10;
        num += digit * power;
        power = power * this->base;
    }
    return num;
}

void Number::fromDec(int newBase, int num) {
    int cnum = num;
    nr_digits = 0;
    base = newBase;
    while (cnum > 0) {
        cnum /= base;
        nr_digits++;
    }
    value = new char[nr_digits + 1];
    value[nr_digits] = '\0';
    int k = 1;
    while (num > 0) {
        char digit;
        if (num % base >= 0 && num % base <= 9)
            digit = (char) (num % base + '0');
        else
            digit = (char) (num % base - 10 + 'A');
        value[nr_digits - k] = digit;
        num /= base;
        k++;
    }
}

Number::Number(const char* value, int base) {
    int lungime = strlen(value);
    this->value = new char[lungime + 1];
    this->base = base;
    this->nr_digits = lungime;
    strcpy(this->value, value);
    this->value[lungime] = '\0';
}

Number::Number() {
    base = -1;
    nr_digits = -1;
    value = nullptr;
}

Number::Number(int value) {
    base = 10;
    nr_digits = (int) (log10(value)) + 1;
    this->value = new char[nr_digits + 1];
    this->value[nr_digits] = '\0';
    int k = 1;
    while (value > 0) {
        this->value[nr_digits - k] = (char) (value % 10 + '0');
        value /= 10;
        k++;
    }
}

Number::~Number() {
    base = -1;
    nr_digits = -1;
    delete value;
}

Number::Number(const Number& obj) {
    this->base = obj.base;
    this->nr_digits = obj.nr_digits;
    this->value = new char[nr_digits + 1];
    strcpy(this->value, obj.value);
    this->value[nr_digits] = '\0';
}

Number::Number(Number&& obj) {
    this->value = obj.value;
    obj.value = nullptr;
    nr_digits = obj.nr_digits;
    base = obj.base;
}

char Number::operator[](int index) {
    return value[index];
}

Number& Number::operator=(int value) {
    if (base == -1) {
        fromDec(10, value);
    } else {
        fromDec(this->base, value);
    }
    return (*this);
}

Number& Number::operator=(const Number& obj) {
    this->base = obj.base;
    this->nr_digits = obj.nr_digits;
    strcpy(value, obj.value);
    return (*this);
}

Number& Number::operator=(const char* value) {
    delete this->value;
    nr_digits = strlen(value);
    this->value = new char[nr_digits + 1];
    strcpy(this->value, value);
    return (*this);
}

void Number::SwitchBase(int newBase) {
    int nrDec = toDec();
    delete value;
    fromDec(newBase, nrDec);
}

void Number::Print() {
    printf("%s\n", value);
}

int Number::GetDigitsCount() {
    return nr_digits;
}

int Number::GetBase() {
    return base;
}

Number operator+(const Number& obj1, const Number& obj2) {
    Number rezultat;
    int baseMax;
    if (obj1.base > obj2.base)
        baseMax = obj1.base;
    else
        baseMax = obj2.base;
    int num1, num2;
    rezultat.base = baseMax;
    num1 = obj1.toDec();
    num2 = obj2.toDec();
    int sum = num1 + num2;
    rezultat.fromDec(baseMax, sum);
    return rezultat;
}

Number operator-(const Number& obj1, const Number& obj2) {
    Number rezultat;
    int baseMax;
    if (obj1.base > obj2.base)
        baseMax = obj1.base;
    else
        baseMax = obj2.base;
    int num1, num2;
    rezultat.base = baseMax;
    num1 = obj1.toDec();
    num2 = obj2.toDec();
    int sum = num1 - num2;
    rezultat.fromDec(baseMax, sum);
    return rezultat;
}

bool operator>(const Number& obj1, const Number& obj2) {
    int num1, num2;
    num1 = obj1.toDec();
    num2 = obj2.toDec();
    if (num1 > num2)
        return true;
    return false;
}

bool operator<(const Number& obj1, const Number& obj2) {
    int num1, num2;
    num1 = obj1.toDec();
    num2 = obj2.toDec();
    if (num1 < num2)
        return true;
    return false;
}

bool operator>=(const Number& obj1, const Number& obj2) {
    return !(obj1 < obj2);
}

bool operator<=(const Number& obj1, const Number& obj2) {
    return !(obj1 > obj2);
}

bool operator==(const Number& obj1, const Number& obj2) {
    return !(obj1 > obj2 && obj1 < obj2);
}

Number& operator+=(Number& obj1, const Number& obj2) {
    obj1 = obj1 + obj2;
    return obj1;
}

Number& operator--(Number& obj) {
    char* aux;
    aux = new char[obj.nr_digits];
    aux[obj.nr_digits - 1] = '\0';
    obj.nr_digits = obj.nr_digits - 1;
    strcpy(aux, obj.value + 1);
    delete obj.value;
    obj.value = new char[obj.nr_digits + 1];
    obj.value[obj.nr_digits] = '\0';
    strcpy(obj.value, aux);
    return obj;
}

Number& operator--(Number& obj, int) {
    char* aux;
    aux = new char[obj.nr_digits];
    aux[obj.nr_digits - 1] = '\0';
    obj.nr_digits = obj.nr_digits - 1;
    for (int i = 0; i < obj.nr_digits; i++)
        aux[i] = obj[i];
    delete obj.value;
    obj.value = new char[obj.nr_digits + 1];
    obj.value[obj.nr_digits] = '\0';
    for (int i = 0; i < obj.nr_digits; i++)
        obj.value[i] = aux[i];
    return obj;
}
