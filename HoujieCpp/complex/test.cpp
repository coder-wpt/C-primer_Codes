#include <iostream>
#include "My_Complex.h"


int main()
{
    My_Complex c1(1,2);
    My_Complex c2(2,3);

    std::cout<<c1<<c2<<std::endl;
    
    c1+=c2;
    std::cout<<c1<<std::endl;

    c2=c1+2;
    std::cout<<c2<<std::endl;
    
    return 0;
}

