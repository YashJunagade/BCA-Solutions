/*a) Write a C++ program to interchange values of two integer numbers. (Use call by reference)*/

#include <bits/stdc++.h>
using namespace std;

void callByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b;
    cout << "Enter two numbers : ";
    cin >> a >> b;

    cout << "Values Before swapping : ";
    cout << "a : " << a << " b : " << b << endl;
    callByReference(a, b);
    cout << "Values After swapping : ";
    cout << "a : " << a << " b : " << b << endl;
    return 0;
}