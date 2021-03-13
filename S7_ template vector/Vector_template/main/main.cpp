
#include "Vector.h"
#include "grade.h"
    
#include <iostream>

using namespace std;

int main() 
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << "K = " << a << " f = " << b << "\n\n";

    Vector<int> x;
    x.push(10);
    x.push(11);
    x.push(12);
    x.delete_(1);
    x.insert(101, 1);
    x.insert(5, 20);
    x.set(100, 0); 
    x.sort(Greater);
    for(int i = 0; i < x.count_(); i++)
        cout << x.get(i) << " ";
    cout << "\n";
    cout << x.firstIndexOf(101, Equal);
    return 0;
}
