/*Create a C++ class College, with data members CollegeId, CollegeName, Establishment_year, University_Name.
Overload operators>> and << to accept and display College information.*/

#include <bits/stdc++.h>
using namespace std;

class College
{
    int cid;
    string cname, eyear, uname;

public:
    College() {}

    friend istream &operator>>(istream &is, College &c);
    friend ostream &operator<<(ostream &os, College &c);
};

istream &operator>>(istream &is, College &c)
{
    cout << "Enter College ID: ";
    is >> c.cid;
    cout << "Enter College Name: ";
    is >> c.cname;
    cout << "Enter Establishment Year: ";
    is >> c.eyear;
    cout << "Enter University Name: ";
    is >> c.uname;
    return is;
}

ostream &operator<<(ostream &os, College &c)
{
    os << "College ID: " << c.cid << endl;
    os << "College Name: " << c.cname << endl;
    os << "Establishment Year: " << c.eyear << endl;
    os << "University Name: " << c.uname << endl;
    return os;
}

int main()
{
    College c;
    cin >> c;
    cout << c;
    return 0;
}