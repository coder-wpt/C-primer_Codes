#pragma once
#include<iostream>
using namespace std;

class Component{

public:
    Component(){
        cout << "Component::Component()" << endl;
    }
    ~Component(){
        cout << "Component::~Component()" << endl;
    }
    
};

class Base
{
public:
    Base() {
        cout<<"Base::construct()" << endl;
    }
    ~Base() {
        cout << "Base::~Base()" << endl;
    }

    virtual void vfun(){};
private:

    Component c1; 
};


class Derived : public Base
{
public:
    Derived (){
        cout << "Derived::Derived()" <<endl;
    }
    ~Derived(){
        cout << "Derived::~Derived()" <<endl;
    }

private:
};
