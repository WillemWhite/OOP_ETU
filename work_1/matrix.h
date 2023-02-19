#ifndef TMATRIX_H
#define TMATRIX_H

#include <iostream>

#include "number.h"

class TMatrix
{
private:
    int n = 0;
    number** elements = nullptr;
public:
    TMatrix();
    TMatrix(int, number**&);
    TMatrix(const TMatrix&);
    ~TMatrix();
public:
    // Methods for task_1
    friend std::ostream& operator<< (std::ostream&, const TMatrix&);
    void toDefaultMatrix();
    number findDet();
    int findRank();
    void transpose();
};

#endif // TMATRIX_H
