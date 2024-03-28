/*Create a C++ class MyMatrix and Write necessary member functions for the following:
i. To accept a Matrix
ii. To display a Matrix
iii. Overload unary '-' operator to calculate transpose of a Matrix.
iv. Overload unary '++' operator to increment matrix elements by 1.*/

#include <bits/stdc++.h>
using namespace std;

class MyMatrix
{
    int r, c;
    int matrix[100][100];

public:
    MyMatrix(int r, int c) : r(r), c(c) {}

    void setMatrix()
    {
        cout << "Enter elment for " << r << "x" << c << " matrix : " << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    void displayMatrix()
    {
        cout << "Matrix : " << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    MyMatrix operator-()
    {
        MyMatrix transpose(c, r);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                transpose.matrix[j][i] = matrix[i][j];
            }
        }

        transpose.displayMatrix();
    }

    MyMatrix operator++()
    {
        MyMatrix increment(r, c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                increment.matrix[i][j] = matrix[i][j] + 1;
            }
        }

        increment.displayMatrix();
    }
};

int main()
{
    int r, c;
    cout << "Enter rows and columns : " << endl;
    cin >> r >> c;
    MyMatrix m1(r, c);
    m1.setMatrix();
    m1.displayMatrix();

    cout << "Transpose Of Matrix : " << endl;
    m1.operator-();

    cout << "Increment of Matrix : " << endl;
    m1.operator++();

    return 0;
}