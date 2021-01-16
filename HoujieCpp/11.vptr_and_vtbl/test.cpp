#include <iostream>
#include <vector>
#include "polymorphism.hpp"

//polymorphism
//c++ 看到一个函数调用有两个考量
//1.静态绑定 2.动态绑定
//1.call
//2.通过指针调用，指针向上转型 up-cast ，调用的是虚函数
//
//多态polymorhism

int main()
{
    std::vector<animal*>a;
    animal* a1 = new animal;
    animal* pig2 = new buru("female");
    animal* pig1 = new buru("male");
    animal* h1 = new human("张三","123","male");
    
    a.push_back(a1);
    a.push_back(pig2);
    a.push_back(pig1);
    a.push_back(h1);

    for(auto it:a)
    {
        delete it;
    }
    
    return 0;
}

