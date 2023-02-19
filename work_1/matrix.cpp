#include <iostream>
#include <cmath>

#include "matrix.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ostream;

TMatrix::TMatrix(vector<number> arr)
{
    elements.resize(arr.size());
    for (int i = 0; i < arr.size(); i++)
        elements.push_back(arr[i]);
}

ostream& operator<< (ostream& os, TMatrix& p)
{
    int n = sqrt(p.elements.size());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << p.elements[i * n + j] << " ";
        }
        cout << endl;
    }

    return os;
}
