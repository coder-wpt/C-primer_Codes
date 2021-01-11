#include <iostream>
#include "Observer.hpp"

using namespace std;



int main()
{
    
    O2 o2;
    O1 o1;
    Subject s1;

    s1.attach(&o1);
    s1.attach(&o2);
    s1.set_value(1);
    s1.set_value(2);
    s1.set_value(3);

    return 0;
}

