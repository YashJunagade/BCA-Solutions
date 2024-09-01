/*Write a C++ program to create a class Machine with data members Machine_Id, Machine_Name, Price. Create and initialize all values of
Machine object by using parameterized constructor and copy constructor. Display details of Machine using setw() and setprecision().*/

#include <bits/stdc++.h>
using namespace std;

class Machine
{
    int mid;
    string mname;
    float price;

public:
    Machine(int id, string name, float p)
    {
        mid = id;
        mname = name;
        price = p;
    }

    Machine(Machine &m)
    {
        mid = m.mid;
        mname = m.mname;
        price = m.price;
    }

    void display()
    {
        cout << left << setw(20) << "Machine Id : " << setprecision(10) << mid << endl;
        cout << left << setw(20) << "Machine Name : " << setprecision(10) << mname << endl;
        cout << left << setw(20) << "Price : Rs." << setprecision(10) << price << endl;
    }
};

int main()
{
    int id;
    string name;
    float p;

    cout << "Enter Machine Id : ";
    cin >> id;
    cout << "Enter Machine Name : ";
    cin >> name;
    cout << "Enter Price : ";
    cin >> p;

    Machine m1(id, name, p);
    Machine m2(m1);

    m1.display();
    m2.display();
    return 0;
}