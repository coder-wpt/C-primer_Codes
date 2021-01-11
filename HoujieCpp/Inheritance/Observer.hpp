#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Subject;

class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}

    virtual void update(Subject* sub,int value)=0;
private:

};


class Subject
{
private:
    int m_value;
    vector<Observer*>m_views;

public:
    void attach(Observer* obs)
    {
        m_views.push_back(obs);
    }

    void set_value(int value)
    {
        m_value = value;
        notify();
    }

    void print()
    {
        cout << "subject_value=" <<m_value <<endl;
    }

    void notify()
    {
        for(size_t i = 0; i<m_views.size() ; ++i)
           m_views[i]->update(this,m_value); 
    }
};


class O1 : public Observer
{
public:
    O1(){};
    virtual ~O1(){};
    virtual void update(Subject* sub,int value)
    {
        sub->print();
        m_value = value;
        cout << "o1 value=" << m_value <<endl;
    }
private:
    int m_value;

};

class O2 : public Observer
{
public:
    O2(){};
    virtual ~O2(){};
    virtual void update(Subject* sub,int value)
    {
        sub->print();
        m_value = value*2;
        cout << "o2 value=" << m_value <<endl;
    }
private:
    int m_value;

};

