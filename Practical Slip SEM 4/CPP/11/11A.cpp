/*Create a C++ class MyArray, which contains single dimensional integer array of a given size. Write a
member function to display sum of given array elements. (Use Dynamic Constructor and Destructor)*/

#include <bits/stdc++.h>
using namespace std;

class myArray
{
    int n, *arr;

public:
    myArray(int size)
    {
        n = size;
        arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cout << "Enter element " << i + 1 << " : ";
            cin >> arr[i];
        }
    }

    void sumArray()
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        cout << "Sum : " << sum << endl;
    }

    ~myArray()
    {
        delete[] arr;
    }
};

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    myArray obj(n);
    obj.sumArray();
    return 0;
}