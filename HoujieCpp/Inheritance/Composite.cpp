#include <iostream>
#include "Composite.hpp"
using namespace std;

int main()
{
 
    Component* fir = new Composite(0);
    Component* sec = new Composite(1);
    Component* file1 = new Primitive(2);
    Component* file2 = new Primitive(3);
    Component* file3 = new Primitive(4);
    


    fir->add(sec);
    fir->add(file1);
    sec->add(file2);
    sec->add(file3);
    
    fir->print();
    


    return 0;
}

