#pragma once
#include<iostream>

//partial specialization
template<typename F,typename T>
class vector
{
public:
    vector() {}
    ~vector() {}

private:

};

template<typename T>
class vector<bool,T>
{
    
};

template <typename T>
class C
{

};

template <typename T>
class C<T*>
{

};

//template tempalte parameter
template<typename T,
    template<typename Tq>
    class Container>
class XCLS
{

};

//variadic tempaltes 可变模板参数

void print()
{

}

template<typename T,typename... types>
void print(const T&firstArg,const types&... args)
{
    std::cout<<firstArg<<std::endl;
    print(args...);
}


