#pragma once
class Number
{
private:
    char number[100];
    int base;
public:
    Number();
    Number(int value);
    Number(const char* value, int base); // where base is between 2 and 16
    ~Number();

    Number(const Number& d);
    Number(Number&& d);

    Number& operator=(const Number& d);
    Number& operator=(int value);
    Number& operator=(const char* value);

    friend Number operator+(const Number& d1, const Number& d2);
    friend Number operator-(const Number& d1, const Number& d2);
    Number& operator+=(const Number & d);
    
    char operator[](int index);
    Number operator!();
    bool operator>(const Number& d);
    Number& operator--();
    Number operator--(int value);

    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
};