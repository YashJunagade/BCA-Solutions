/*) Create a C++ class MyArray with data members
int *arr
- int size
Write necessary member functions to accept and display Array elements. Overload the following operators:
Operator     Example               Purpose
- (Unary)       -A1             Reverse array elements.
+(Binary)     A2=A1+n           Add constant n to all array elements.*/

#include <bits/stdc++.h>
using namespace std;

class MyArray
{
    int *arr, size;

public:
    MyArray(int size)
    {
        this->size = size;
        arr = new int[size];
    }

    void setArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter " << i + 1 << " element : ";
            cin >> arr[i];
        }
    }

    ~MyArray()
    {
        delete[] arr;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    MyArray operator-()
    {
        MyArray result(size);
        for (int i = 0; i < size; i++)
        {
            result.arr[i] = arr[size - i - 1];
        }
        return result;
    }

    MyArray operator+(int n)
    {
        MyArray result(size);
        for (int i = 0; i < size; i++)
        {
            result.arr[i] = arr[i] + n;
        }
        return result;
    }
};

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    MyArray a(n);
    a.setArray();
    cout << "array : ";
    a.display();

    cout << "Reverse array : ";
    MyArray b = -a;
    b.display();

    cout << "Enter n constant : ";
    cin >> n;
    cout << "array after adding n :";
    MyArray c = a + n;
    c.display();
    return 0;
}