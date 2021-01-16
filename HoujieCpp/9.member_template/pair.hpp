#pragma once

template<class T1,class T2>
struct pair
{
public:
    pair():first(T1()),second(T2()) {}
    pair(const T1&a,const T2&b):first(a),second(b){}
    ~pair() {}

    template<class U1,class U2>
    pair(const pair<U1,U2>&p):first(p.first),second(p.second){}

private:
    T1 first;
    T2 second;
};

//Base1* ptr = new Derived1;
//智能指针模拟up-cast 
//shared_ptr<Base1>sptr(new Derived1);
