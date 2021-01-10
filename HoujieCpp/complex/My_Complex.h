#pragma once
#include <iostream>


class My_Complex
{
public:
    My_Complex() {}
    My_Complex(double x = 0,double y = 0):re(x),im(y){}
    My_Complex(const My_Complex& rhs){
        this->re=rhs.re;
        this->im=rhs.im;
    }  
    
    My_Complex& operator = (const My_Complex& rhs)
    {
        My_Complex temp(rhs);
        this->re = temp.re;
        this->im = temp.im;
        return *this;
    }
    ~My_Complex() {}

    double real()const
    {
        return re;
    }

    double image()const
    {
        return im;
    }

    
    My_Complex& operator +=(const My_Complex& rhs)
    {
         re += rhs.real();
         im += rhs.image();
         return *this;
    }



private:
    double re,im;
};


inline std::ostream& operator<<(std::ostream& os, const My_Complex& rhs)
{
    return os << "(" << rhs.real() << "," << rhs.image() << ")";        
}

//如果+设计到complex类中，那么无法应付复数+实数的情况
inline My_Complex operator +(const My_Complex& x,const My_Complex& y)
{
    return My_Complex(x.real() + y.real(), x.image()+ y.image());
}

inline My_Complex operator +(const My_Complex& x,double y)
{
    return My_Complex(x.real() + y, x.image());
}


inline My_Complex operator +(double x,const My_Complex& y)
{
    return My_Complex(x + y.real(),  y.image());
}


