#include <iostream>
#include <cmath>
#include <limits>

#include "application.h"
#include "number.h"
#include "matrix.h"

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

#define SKIP_UNTIL_ENDLINE cin.ignore(numeric_limits<streamsize>::max(), '\n')

int TApplication::exec()
{
    int choice;

    TMatrix* userMatrix = new TMatrix(true);

    while (true)
    {
        choice = menu();
        int n;

        switch (choice)
        {
        case 0:
            return 0;
        case 1:
        {
            cout << "Enter size: ";
            cin >> n;
            SKIP_UNTIL_ENDLINE;

            cout << "enter the matrix elements as complex numbers like" << endl
                << "'(a, b)', where:" << endl
                << "'a' is the real part;" << endl
                << "'b' is the imaginary part." << endl
                << "Complex numbers are entered in the row" << endl
                << "corresponding to the row of the matrix, for example:" << endl
                << "[1]: (1,2)  (2.4)    (0,-234.3)  (2) " << endl
                << "[2]: (3,0)  (0,23)   (,44)       (2) " << endl
                << "[3]: (4)    (33,-23) (2,343)     (4) " << endl
                << "[4]: (6)    (7)      (8,3)   (20,20)" << endl
                << endl;

            number** inputArr = new number * [n];
            inputArr = new number * [n];
            for (int i = 0; i < n; i++)
            {
                inputArr[i] = new number[n];
                cout << "[" << i + 1 << "] row: ";

                for (int j = 0; j < n; j++)
                    cin >> inputArr[i][j];
                SKIP_UNTIL_ENDLINE;
            }
            userMatrix = new TMatrix(n, inputArr);
            for (int i = 0; i < n; i++)
                delete[] inputArr[i];

            cout << endl;
            break;
        }
        case 2:
        {
            number d = userMatrix->findDet();
            cout << "Determinant: " << d << endl;
            cout << endl;
            break;
        }
        case 3:
            userMatrix->transpose();
            break;
        case 4:
        {
            int r = userMatrix->findRank();
            cout << "Rank: " << r << endl;
            cout << endl;
            break;
        }
        case 5:
        {
            cout << *userMatrix << endl;
            break;
        }
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
    cout << "4 - find rank" << endl;
    cout << "5 - print matrix" << endl;
    cout << "0 - exit" << endl << "> ";
    cin >> choice;
    cout << endl;

    return choice;
}
