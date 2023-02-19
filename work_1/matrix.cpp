#include <iostream>
#include <cmath>

#include "matrix.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::ios;

TMatrix::TMatrix()
{
    n = 0;
    elements = nullptr;
}

TMatrix::TMatrix(int n, number**& arr)
{
    this->n = n;
    elements = arr;
}

TMatrix::TMatrix(const TMatrix& other)
{
    n = other.n;

    number** newArr = new number * [n];
    for (int i = 0; i < n; i++)
    {
        newArr[i] = new number[n];
        for (int j = 0; j < n; j++)
            newArr[i][j] = other.elements[i][j];
    }
    elements = newArr;
}


TMatrix::~TMatrix()
{
    if (elements) {
        for (int i = 0; i < n; i++)
            delete[] elements[i];
        delete[] elements;
    }
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

void TMatrix::toDefaultMatrix()
{
    if (elements) {
        for (int i = 0; i < n; i++)
            delete[] elements[i];
        delete[] elements;
    }

    n = 2;

    number** defaultArr = new number * [2];
    defaultArr[0] = new number[2]{ 1, 0 };
    defaultArr[1] = new number[2]{ 0, 1 };
    elements = defaultArr;
}
