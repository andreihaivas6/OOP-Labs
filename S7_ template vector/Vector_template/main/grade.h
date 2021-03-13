#pragma once
float operator"" _Kelvin(unsigned long long x)
{
    return x - 273.15;
}
float operator"" _Fahrenheit(unsigned long long x)
{
    return (float)(x - 32) / 1.8;
}