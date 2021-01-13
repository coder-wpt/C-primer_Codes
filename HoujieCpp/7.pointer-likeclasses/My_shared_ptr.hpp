#pragma once

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

