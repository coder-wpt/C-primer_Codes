#include <iostream>
#include "StrVec.h"
using namespace std;

int main()
{
    StrVec vec;
    std::cout<<vec.begin()<<std::endl;
    std::cout<<vec.size()<<std::endl;
    std::cout<<vec.capacity()<<std::endl;
    
    return 0;
}

