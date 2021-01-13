#pragma once


/*class Fraction
{
public:
    Fraction(int num,int den=1):m_numerator(num),m_denominator(den) {}
    ~Fraction() {}

    Fraction operator+(const Fraction& f){
    }

private:
    int m_numerator;
    int m_denominator;
};*/


class Fraction
{
public:
    explicit Fraction(int num,int den=1):m_numerator(num),m_denominator(den) {}//取消隐式转换
    ~Fraction() {}

    Fraction operator+(const Fraction& f){
    }

private:
    int m_numerator;
    int m_denominator;
};

Fraction f(3,5);
Fraction d2=f+4;//explicit 将构造函数取消隐式转换之后，4无法转换为fraction
