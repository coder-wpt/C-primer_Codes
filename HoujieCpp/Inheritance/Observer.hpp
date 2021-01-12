#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
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
*/

class observer{
public:
    virtual void updata(int) = 0;
    virtual void printval() = 0;
};

class subject{
public:
    virtual void attach(observer*) = 0;
    virtual void detach(observer*) = 0;
    virtual void notify() = 0;
};

class o1 : public observer
{
public:
    o1(subject* sub):m_sub(sub){}
    void updata(int val)
    {
        value = val;
        printval();
    }

    void printval()
    {
        cout << "o1 value = " << value << endl;
    }
private:
    subject* m_sub;
    int value;
};

class o2 : public observer
{
public:
    o2(subject* sub):m_sub(sub){}
    void updata(int val)
    {
        value = val;
        printval();
    }

    void printval()
    {
        cout << "o2 value = " << value << endl;
    }
private:
    subject* m_sub;
    int value;
};

class s1 : public subject
{
public:
    void attach(observer* o)
    {
        all_obs.push_back(o);
    }

    void detach(observer* o)
    {
        auto it = find(all_obs.begin(),all_obs.end(),o);
        if(it == all_obs.end()){
            return;
        }else{
            it=all_obs.erase(it);
        }
    }

    void notify()
    {
        for(auto it : all_obs)
        {
            it->updata(m_value);
        }
    }

    void set_val(int val)
    {
        m_value = val;
        notify();
    }

private:
    vector<observer*>all_obs;
    int m_value;
};
