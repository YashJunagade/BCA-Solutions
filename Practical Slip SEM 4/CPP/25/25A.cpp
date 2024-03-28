/*Write a C++ program to calculate mean, mode and median of three integer numbers.
(Use Inline function)*/

#include <bits/stdc++.h>
using namespace std;

inline double mean(int n1, int n2, int n3)
{
    return (n1 + n2 + n3) / 3.0;
}

inline double mode(int n1, int n2, int n3)
{
    if (n1 == n2 && n2 == n3)
        return n1;
    else if (n1 == n2 || n2 == n3)
        return n2;
    else
        return -1;
}
inline double median(int n1, int n2, int n3)
{
    int arr[] = {n1, n2, n3};
    sort(arr, arr + 3);

    return arr[1];
}

int main()
{
    int n1, n2, n3;
    cout << "Enter three numbers : ";
    cin >> n1 >> n2 >> n3;

    cout << "Mean : " << mean(n1, n2, n3) << endl;
    if (mode(n1, n2, n3) != -1)
    {
        cout << "Mode : " << mode(n1, n2, n3) << endl;
    }
    else
    {
        cout << "Mode : No mode found" << endl;
    }

    cout << "Median : " << median(n1, n2, n3) << endl;
    return 0;
}