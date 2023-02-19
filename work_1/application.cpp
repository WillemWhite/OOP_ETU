#include <iostream>
#include <cmath>
#include <vector>

#include "application.h"
#include "number.h"
#include "matrix.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

TApplication::TApplication()
{
    // ...
}

int TApplication::exec()
{
    int choice;

    int n;
    vector<number> vec = { 1, 0, 0, 1 };

    while (true)
    {
        choice = menu();
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            cout << "Enter size: ";
            cin >> n;
            vec.resize(n);
            cout << "Enter elements: ";
            for (int i = 0; i < n * n; i++)
            {
                cout << i + 1 << ": ";
                cin >> vec[i];
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
        {
            TMatrix m(vec);
            cout << m << endl;
        }
        break;
        default:
            break;
        }
    }
}

int TApplication::menu()
{
    int choice;
    cout << "1 - enter matrix" << endl;
    cout << "2 - find determinant" << endl;
    cout << "3 - transpose matrix" << endl;
    cout << "4 - find rang" << endl;
    cout << "5 - print matrix" << endl;
    cout << "0 - exit" << endl << "> ";
    cin >> choice;
    cout << endl;

    return choice;
}
