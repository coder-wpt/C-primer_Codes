#include <iostream>
#include "Singleton.hpp"
using namespace std;

int main()
{

    Singleton& i1 = Singleton::get_instance();
    Singleton& i2 = Singleton::get_instance();
    Singleton& i3 = Singleton::get_instance();
    return 0;
}

