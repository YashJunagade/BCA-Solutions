/*Write a C++ program to check maximum and minimum of two integer numbers.
(Use Inline function and Conditional operator)*/

#include <bits/stdc++.h>
using namespace std;

inline int minMax(int n1, int n2)
{
    int min = (n1 < n2) ? n1 : n2;
    int max = (n1 > n2) ? n1 : n2;
    cout << "Minimum  : " << min << endl;
    cout << "Maximum : " << max << endl;
}

int main()
{
    int n1, n2;
    cout << "Enter two numbers : ";
    cin >> n1 >> n2;

    minMax(n1, n2);
    return 0;
}