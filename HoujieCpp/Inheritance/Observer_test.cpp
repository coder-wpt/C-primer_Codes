#include <iostream>
#include "Observer.hpp"

using namespace std;



int main()
{
    s1* sub1 = new s1;

    observer *obs1 = new o1(sub1);
    
    observer *obs2 = new o2(sub1);


    sub1->attach(obs1);
    sub1->attach(obs2);
    sub1->set_val(1);
    sub1->set_val(2);
    
    return 0;
}

