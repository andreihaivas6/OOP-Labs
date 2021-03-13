
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Vector
{
private:
    int value[100];
    int size;

public:
    Vector() : size(0), value() {}

    bool Add(int x)
    {
        if (size == 100)
            return false;
        value[size++] = x;
        return true;
    };

    bool Delete(int index)
    {
        if (index >= size || index < 0)
            return false;
        for (int i = index; i < size - 1; i++)
            value[i] = value[i + 1];
        size--;
        return true;
    };

    void Print()
    {
        for (int i = 0; i < size; i++)
            cout << value[i] << " ";
        cout << "\n";
    };

    void Iterate(void (*modify)(int&))
    {
        for (int i = 0; i < size; i++)
            modify(value[i]);
    };

    void Filter(bool (*remove)(int))
    {
        for (int i = 0; i < size; i++)
            if (remove(value[i]))
            {
                Delete(i);
                i--;
            }
    }

};

int main()
{
    vector <string> v1 = { "ana", "are", "mere", "mera", "mer", "qwerty", "b", "a" };
    auto f = [](string a, string b) -> bool
    {
        if (a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    };
    sort(v1.begin(), v1.end(), f);
    //bool gasit;
    //do {
    //    gasit = false;
    //    for (auto j = v1.begin(); j != v1.end() - 1; j++)
    //        if (f(*j, *(j + 1)))
    //        {
    //            swap(*j, *(j + 1));
    //            gasit = true;
    //        }
    //} while (gasit);
    for (string i : v1)
        cout << i << "\n";

    

    int v2[] = { 12, 45, 65, 85, 76, 124, 64, 2 };
    auto maxElem = [v2]() -> int
    {
        int maxim = v2[0];
        for (int i = 1; i < sizeof(v2) / sizeof(int); i++)
            if (v2[i] > maxim)
                maxim = v2[i];
        return maxim;
    };
    cout << "\n" << maxElem() << "\n\n";

    

    Vector v3;
    v3.Add(4);
    v3.Add(2);
    v3.Add(6);
    v3.Add(10);
    v3.Print();

    auto f1 = [](int& el) -> void { el *= 2; };
    v3.Iterate(f1);
    v3.Print();
    auto f2 = [](int  el) -> bool { return el < 10; };
    v3.Filter(f2);
    v3.Print();

    return 0;
}



    /* Ex. 1
    
    auto compare = [](string a, string b) -> bool
    {
        if (a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    };
    bool gasit;
    do {
        gasit = false;
        for (auto i = v.begin(); i != v.end(); i++)
            for (auto j = v.begin(); j != v.end() - 1; j++)
                if (!compare(*j, *(j + 1)))
                {
                    swap(*j, *(j + 1));
                    gasit = true;
                }
    } while (gasit);*/
