#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class TComplex
{
    double re, im;

public:
    TComplex();
    TComplex(double num);
    TComplex(const TComplex& other);
public:
    TComplex operator+(const TComplex&);
    TComplex operator-(const TComplex&);
    TComplex operator-();
    TComplex operator* (const TComplex&);
    TComplex operator/ (const TComplex&);
    TComplex operator+=(const TComplex&);
    TComplex operator-=(const TComplex&);
    TComplex operator*=(const TComplex&);
    TComplex operator/=(const TComplex&);
    bool operator==(const TComplex&);
    bool operator!=(const TComplex&);
    friend TComplex operator* (double, const TComplex&);
    friend std::ostream& operator<<(std::ostream&, const TComplex&);
    friend std::istream& operator>>(std::istream&, TComplex&);
};

#endif // COMPLEX_H
