#include <iostream>
#include <cmath>

#include "matrix.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::ios;
using std::swap;

TMatrix::TMatrix(bool def = false)
{
    if (def) {
        n = 2;

        number** defaultArr = new number * [2];
        defaultArr[0] = new number[2]{ 1, 0 };
        defaultArr[1] = new number[2]{ 0, 1 };
        elements = defaultArr;
    }
    else {
        n = 0;
        elements = nullptr;
    }
}

TMatrix::TMatrix(int n, number**& arr)
{
    this->n = n;
    elements = new number * [n];
    for (int i = 0; i < n; i++)
    {
        elements[i] = new number[n];
        for (int j = 0; j < n; j++)
            elements[i][j] = arr[i][j];
    }
}

TMatrix::TMatrix(const TMatrix& other)
{
    n = other.n;

    elements = new number * [n];
    for (int i = 0; i < n; i++)
    {
        elements[i] = new number[n];
        for (int j = 0; j < n; j++)
            this->elements[i][j] = other.elements[i][j];
    }
}

TMatrix::~TMatrix()
{
    if (elements)
        for (int i = 0; i < n; i++)
            delete[] elements[i];
}

TMatrix* TMatrix::getMatrWithoutRowAndCol(int row, int col)
{
    auto resArr = new number * [n - 1];
    int curRow = 0;
    for (int i = 0; i < n; i++)
    {
        resArr[i] = new number[n - 1];
        int curCol = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == row)
                break;
            if (j != col) {
                resArr[curRow][curCol] = elements[i][j];

                // Moving to the next element
                if (curCol != n - 2) {
                    curCol++;
                }
                else {
                    curCol = 0;
                    curRow++;
                }
            }
        }
    }

    auto resMatrix = new TMatrix(n - 1, resArr);
    return resMatrix;
}

number TMatrix::findDet()
{
    if (n == 2)
        return elements[0][0] * elements[1][1] - elements[0][1] * elements[1][0];
    if (n == 1)
        return elements[0][0];
    if (n < 1) {
        cout << "Finding determinant is impossible!" << endl;
        return NULL;
    }
    else {
        number det = 0;
        for (int j = 0; j < n; j++)
        {
            auto matrWithoutRowAndCol = this->getMatrWithoutRowAndCol(0, j);
            number minor = matrWithoutRowAndCol->findDet();
            if (j & 1)
                det += -elements[0][j] * minor;
            else
                det += elements[0][j] * minor;

            delete matrWithoutRowAndCol;
        }

        return det;
    }
}

void TMatrix::transpose()
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (i != j)
                swap(elements[i][j], elements[j][i]);

    cout << "Matrix transposed! Press 5 to print it." << endl << endl;
}

void TMatrix::swapRows(int row1, int row2)
{
    for (int i = 0; i < n; i++)
    {
        number temp = elements[row1][i];
        elements[row1][i] = elements[row2][i];
        elements[row2][i] = temp;
    }
}

int TMatrix::findRank()
{
    TMatrix cpMatrix = *this;
    number** cpArr = cpMatrix.elements;
    int rank = 0;

    for (int col = 0; col < n; col++)
    {
        if (cpArr[rank][col] != 0)
        {
            for (int row = rank + 1; row < n; row++)
            {
                number mult = cpArr[row][col] / cpArr[rank][col];
                for (int i = col; i < n; i++)
                    cpArr[row][i] -= mult * cpArr[rank][i];
            }
            rank++;
        }
        else
        {
            bool increaseRank = false;
            for (int row = rank + 1; row < n; row++)
            {
                if ((cpArr[row][col] != 0) && !increaseRank) {
                    increaseRank = true;
                    cpMatrix.swapRows(row, rank);
                }
                else if (!increaseRank)
                    continue;
                else {
                    number mult = cpArr[row][col] / cpArr[rank][col];
                    for (int i = col; i < n; i++)
                        cpArr[row][i] -= mult * cpArr[rank][i];
                }
            }
            if (increaseRank)
                rank++;
        }
    }
    return rank;
}

ostream& operator<< (ostream& os, const TMatrix& m)
{
    for (int i = 0; i < m.n; i++)
    {
        cout << "[" << i + 1 << "] row: ";
        for (int j = 0; j < m.n; j++)
        {
            cout.setf(ios::left);
            cout.width(6);
            cout << m.elements[i][j] << " ";
        }
        cout << endl;
    }

    return os;
}
