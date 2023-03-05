#include <iomanip>
#include <sstream>

#include "complex.h"

TComplex::TComplex()
{
    re = 0, im = 0;
}

TComplex::TComplex(double num)
{
    re = num, im = 0;
}

TComplex::TComplex(const TComplex& other)
{
    re = other.re, im = other.im;
}

TComplex TComplex::operator+(const TComplex& other)
{
    TComplex res;
    res.re = this->re + other.re;
    res.im = this->im + other.im;
    return res;
}

TComplex TComplex::operator-(const TComplex& other)
{
    TComplex res;
    res.re = this->re - other.re;
    res.im = this->im - other.im;
    return res;
}

TComplex TComplex::operator-()
{
    TComplex res;
    res.re = -this->re;
    res.im = -this->im;
    return res;
}

TComplex TComplex::operator*(const TComplex& other)
{
    TComplex res;
    res.re = this->re * other.re - this->im * other.im;
    res.im = this->re * other.im + this->im * other.re;
    return res;
}

TComplex TComplex::operator/(const TComplex& other)
{
    TComplex res;
    int denom = other.re * other.re + other.im * other.im;
    res.re = (this->re * other.re + this->im * other.im) / denom;
    res.im = (other.re * this->im - other.im * this->re) / denom;
    return res;
}

TComplex TComplex::operator+=(const TComplex& other)
{
    TComplex res;
    this->re = this->re + other.re;
    res.re = this->re + other.re;
    this->im = this->im + other.im;
    res.im = this->im + other.im;
    return res;
}

TComplex TComplex::operator-=(const TComplex& other)
{
    TComplex res;
    this->re = this->re - other.re;
    res.re = this->re - other.re;
    this->im = this->im - other.im;
    res.im = this->im - other.im;
    return res;
}

TComplex TComplex::operator*=(const TComplex& other)
{
    TComplex res;
    this->re = this->re * other.re - this->im * other.im;
    res.re = this->re * other.re - this->im * other.im;
    this->im = this->re * other.im + this->im * other.re;
    res.im = this->re * other.im + this->im * other.re;
    return res;
}

TComplex TComplex::operator/=(const TComplex& other)
{
    TComplex res;
    int denom = other.re * other.re + other.im * other.im;
    res.re = (this->re * other.re + this->im * other.im) / denom;
    res.im = (other.re * this->im - other.im * this->re) / denom;
    return res;
}

bool TComplex::operator==(const TComplex& other)
{
    return (this->re == other.re) && (this->im == other.im);
}

bool TComplex::operator!=(const TComplex& other)
{
    return !(*this == other);
}

TComplex operator*(double k, const TComplex& c)
{
    TComplex res;
    res.re = k * c.re;
    res.im = k * c.im;
    return res;
}

std::ostream& operator<<(std::ostream& os, const TComplex& c)
{
    std::ostringstream complexOs;
    complexOs << std::fixed << std::setprecision(2);
    complexOs << "(" << c.re << " + " << c.im << "i)";
    os.width(20);
    os << complexOs.str();
    return os;
}

std::istream& operator>>(std::istream& is, TComplex& c)
{
    char ch;
    bool begin = false;
    bool end = false;
    c.re = 0;
    c.im = 0;
    std::string numb = "0";
    while (true)
    {
        is.get(ch);
        if (ch == '(') {
            begin = true;
            continue;
        }
        if (begin) {
            switch (ch)
            {
            case ' ':
                break;
            case ',':
                c.re += std::stod(numb);
                numb = "0";
                break;
            case '+':
                break;
            case '-':
                numb = ch + numb;
                break;
            case ')':
                end = true;
                c.im += std::stod(numb);
                break;
            default:
                numb += ch;
            }
        }
        if (end)
            break;
    }
    return is;
}
