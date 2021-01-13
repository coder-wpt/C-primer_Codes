#pragma once

class Fraction
{
public:
    Fraction(double a,double b = 1):m_numerator(a),m_denominator(b) {}
    ~Fraction() {}

    
    operator double() const
    {
        return (double)(m_numerator/m_denominator);
    }
    
private:
    double m_numerator;
    double m_denominator;
};

