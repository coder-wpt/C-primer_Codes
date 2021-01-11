#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Component
{
private:
    int value;
public:
    Component(int val){ value=val; }
    virtual void add(Component*){}
    virtual void print(){};
    int get_value()
    {
        return value;
    }
};

class Primitive : public Component
{
public:
    Primitive(int val):Component(val){}
    void print()
    {
        cout << "Primitive " << get_value() <<endl;
    }
};

class Composite : public Component
{
private:
    vector<Component*>c;

public:
    Composite(int val):Component(val){}

    
    void add(Component* elem)
    {
        c.push_back(elem);
    }

    void print()
    {
        cout << " Composite " << get_value() <<endl;
        for(auto it:c)
        {
            cout<<" ";
            it->print();
        }
        cout << " Composit end" <<get_value() <<endl;
    }

};
