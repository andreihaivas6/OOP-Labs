
#include <stdio.h>
#include <iostream>
#include "Map.h"
using namespace std;

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    cout << m[10] << "\n";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    m.Set(10, "CEVA");
    m.Set(1, "altcv");
    const char* x;
    m.Get(10, x);
    cout << x << "\n";
    //m.Clear();
    m.Delete(10);
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    Map <int, const char*> m2;
    m2[20] = "asdas";
    m2[30] = "qqq";
    cout << "\n";
    for (auto [key, value, index] : m2)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    cout << m.Includes(m2);
    return 0;
}
