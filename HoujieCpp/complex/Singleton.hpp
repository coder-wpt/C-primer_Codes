#pragma once
#include<iostream>
#include<memory>
#include<mutex>
using namespace std;

/*
//线程不安全，内存泄漏
class Singleton
{
public:
    ~Singleton() {
        cout<<"destructor called!"<< endl;
    }
    static Singleton* get_instance()
    { if(m_instance_ptr == nullptr)
        {
            m_instance_ptr = new Singleton; 
        } 
        return m_instance_ptr;
    }
    void use() const{ cout << "in use" << endl; }  
private:
    Singleton() {
        cout << "constructor called!" << endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;//=delete
    static Singleton* m_instance_ptr;
};

Singleton* Singleton::m_instance_ptr = nullptr;//静态成员类外定义，分配内存


//智能指针、锁
class Singleton
{

    typedef shared_ptr<Singleton> Ptr;
private:
    Singleton()
    {
        cout << "constructor called!" << endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static Ptr m_instance_ptr;
    static mutex m_mutex;

public:
    ~Singleton()
    {
        cout << "destructor called!" << endl;
    }

    static Ptr get_instance()
    {
        if(m_instance_ptr == nullptr)//double lock
        {
            lock_guard<mutex>lk(m_mutex);
            if(m_instance_ptr == nullptr)
            {
               m_instance_ptr = shared_ptr<Singleton>(new Singleton);
            }
        }
        return m_instance_ptr;
    }

    void use() const
    {
        cout << "in use!" << endl;
    }
};

Singleton::Ptr Singleton::m_instance_ptr = nullptr;
mutex Singleton::m_mutex;
*/

//最推荐的懒汉式单例（magic static）
class Singleton
{
private:
    Singleton(){
        cout << "constructor called!" << endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    ~Singleton()
    {
        cout << "destructor called!" << endl;
    }
    static Singleton& get_instance()
    {
        static Singleton instance;
        return instance;
    }
};
