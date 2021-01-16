#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Shared_ptr{

public:
    Shared_ptr(T *p):ptr(p),pn(new long(1)){}
    Shared_ptr(const Shared_ptr& rhs) : pn(&(++*rhs.pn)),ptr(rhs.ptr){}
    Shared_ptr& operator=(const Shared_ptr& rhs){
        Shared_ptr temp = rhs;
        if( this->ptr == nullptr && --*this->pn == 0 )
        {
            delete ptr;
            delete pn;
        }
        ptr = temp.ptr;
        pn = temp.pn;
        return *this;
    }

    ~Shared_ptr()
    {
        if(--*pn == 0)
        {
            delete ptr;
            delete pn;
        }
    }

    int getref()
    {
        return *pn;
    }

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

private:
    T* ptr;
    long* pn;
};





/*
template <class T>
class My_shared_ptr
{
public:
    My_shared_ptr(T* ptr):px(ptr) {}
    ~My_shared_ptr() {}

    T& operator*() const
    {
        return *px;
    }

    T* operator->() const
    {
        return px;
    }

private:
    T* px;
    long* pn;
};
*/
