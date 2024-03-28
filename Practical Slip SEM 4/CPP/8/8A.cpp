/*Write a C++ program to create a class Number, which contain static data member 'cnt' and member function 'Display()'.
Display() should print number of times display operation is performed irrespective of the object responsible for calling Display().*/

#include <bits/stdc++.h>
using namespace std;

class Number
{
    static int cnt;

public:
    static void display()
    {
        cnt++;
        cout << "cnt = " << cnt << endl;
    }
};

int Number ::cnt = 0;

int main()
{
    Number n1;
    Number n2;
    Number::display();
    n1.display();
    n2.display();
    return 0;
}