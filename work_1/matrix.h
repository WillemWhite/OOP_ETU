#ifndef TMATRIX_H
#define TMATRIX_H

#include <iostream>
#include <vector>

#include "number.h"

class TMatrix
{
    int n;
    std::vector<number> elements;

public:
    TMatrix(std::vector<number>);
    friend std::ostream& operator<< (std::ostream&, TMatrix&);
};

#endif // TMATRIX_H
