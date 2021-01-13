#include <iostream>
#include "Fraction.hpp"
using namespace std;

int main()
{
    Fraction f(4,5);
    double a = 4 + f;
    cout << a << endl;
    return 0;
}

