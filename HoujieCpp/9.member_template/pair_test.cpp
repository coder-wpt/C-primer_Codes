#include <iostream>
#include "pair.hpp"

class Base1{};
class Derived1:public Base1{};
class Base2{};
class Derived2:public Base2{};

int main()
{
    pair<Derived1,Derived2>p;
    pair<Base1,Base2>p2(p);
    return 0;
}

