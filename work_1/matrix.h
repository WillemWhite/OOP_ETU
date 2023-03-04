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
    TMatrix(bool def);
    TMatrix(int n, number**& arr);
    TMatrix(const TMatrix& other);
    ~TMatrix();
public:
    // Methods for task_1
    friend std::ostream& operator<< (std::ostream&, const TMatrix&);
    number findDet();
    int findRank();
    void transpose();
private:
    TMatrix* getMatrWithoutRowAndCol(int row, int col);
    void swapRows(int row1, int row2);
};

#endif // TMATRIX_H
