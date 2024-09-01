/*Create a C++ class Number with integer data member. Write necessary member functions to overload the operator
unary pre and post increment '++'.*/

#include <bits/stdc++.h>
using namespace std;

class Number
{
    int n;

public:
    Number() {}
    Number(int n)
    {
        this->n = n;
    }

    // Post increament operator
    Number operator++(int)
    {
        Number temp = *this;
        n++;
        return temp;
    }

    // Pre increament operator
    Number operator++()
    {
        ++n;
        return *this;
    }

    void display()
    {
        cout << n << endl;
    }
};

int main()
{
    Number n1(10), n2;
    ++n1;
    cout << "Pre Increment: ";
    n1.display();

    cout << "Post Increment: ";
    n2 = n1++;
    n2.display();

    return 0;
}