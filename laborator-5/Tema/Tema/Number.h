#pragma once

class Number

{
    // add data members
    char* value;
    int base=-1;
    int nr_digits=-1;

  public:
    Number(const char* value, int base); // where base is between 2 and 16
    Number();
    Number(int value);
    ~Number();

    // add operators and copy/move constructor

    Number(const Number& obj);//copy constructor

    Number(Number&& obj);//move constructor

    char operator[](int index);//index operator

    Number& operator=(int value);// = operator

    Number& operator=(const Number& obj);

    friend Number operator+(const Number& obj1, const Number& obj2);

    friend Number operator-(const Number& obj1, const Number& obj2);

    friend bool operator>(const Number& obj1, const Number& obj2);
    friend bool operator<(const Number& obj1, const Number& obj2);
    friend bool operator>=(const Number& obj1, const Number& obj2);
    friend bool operator<=(const Number& obj1, const Number& obj2);
    friend bool operator==(const Number& obj1, const Number& obj2);

    friend Number& operator+=(Number& obj1, const Number& obj2);

    Number& operator=(const char* value);

    friend Number& operator--(Number& obj);
    friend Number& operator--(Number& obj,int);


    void SwitchBase(int newBase);

    int toDec()const;
    void fromDec(int newBase, int num);

    void Print();

    int GetDigitsCount(); // returns the number of digits for the current number

    int GetBase(); // returns the current base
};