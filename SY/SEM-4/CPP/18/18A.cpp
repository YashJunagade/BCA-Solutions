/*) Create a C++ class Student with data members Roll_no, S_Name, Class, Percentage.
Accept two students information and display information of student having maximum percentage. (Use this pointer)*/

#include <bits/stdc++.h>
using namespace std;

class Student
{
    int rn;
    string sname, cname;
    float per;

public:
    void setData()
    {
        cout << "Enter Roll Number: ";
        cin >> rn;
        cout << "Enter Student Name: ";
        cin >> sname;
        cout << "Enter Class: ";
        cin >> cname;
        cout << "Enter Percentage: ";
        cin >> per;
    }

    void display()
    {
        cout << "Roll Number: " << rn << endl;
        cout << "Student Name: " << sname << endl;
        cout << "Class: " << cname << endl;
        cout << "Percentage: " << per << endl;
    }

    void maxPercentage(Student s2)
    {
        if (this->per > s2.per)
        {
            this->display();
        }
        else
        {
            s2.display();
        }
    }
};

int main()
{
    Student s1, s2;
    s1.setData();
    s2.setData();
    s1.display();
    s2.display();

    cout << "Student having maximum percentage: " << endl;
    s1.maxPercentage(s2);
    return 0;
}