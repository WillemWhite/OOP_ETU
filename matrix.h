#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#include "number.h"

class TMatrix
{
    int n;
    number** elements;

public:
    TMatrix(bool def);
    TMatrix(int n, number**& arr);
    TMatrix(const TMatrix& other);
    ~TMatrix();
public:
    friend std::ostream& operator<< (std::ostream&, const TMatrix&);
    TMatrix* getMatrWithoutRowAndCol(int row, int col);
    number findDet();
    void swapRows(int row1, int row2);
    int findRank();
    void transpose();
};

#endif // MATRIX_H
