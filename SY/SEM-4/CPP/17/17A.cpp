/*Create a C++ class MyMatrix. Write a C++ program to accept and display a Matrix. Overload binary '-'
operator to calculate subtraction of two matrices.*/

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
        cout << "Enter element for " << r << "x" << c << " matrix : " << endl;
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

    MyMatrix operator-(MyMatrix m2)
    {
        MyMatrix result(r, c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                result.matrix[i][j] = matrix[i][j] - m2.matrix[i][j];
            }
        }
        return result;
    }
};

int main()
{
    int r, c;
    cout << "Enter the rows and columns for Matrix 1: ";
    cin >> r >> c;
    MyMatrix m1(r, c);
    m1.setMatrix();

    cout << "Enter the rows and columns for Matrix 2 : ";
    cin >> r >> c;
    MyMatrix m2(r, c);
    m2.setMatrix();

    cout << "Matrix 1 : " << endl;
    m1.displayMatrix();

    cout << "Matrix 2 : " << endl;
    m2.displayMatrix();

    MyMatrix m3 = m1 - m2;
    cout << "Subtraction of two Matrix 1 and Matrix 2 is : << endl";
    m3.displayMatrix();

    return 0;
}