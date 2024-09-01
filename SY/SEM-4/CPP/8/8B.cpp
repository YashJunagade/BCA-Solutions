/*Create a C++ class Person with data members Person_name, Mobile_number, Age, City. Write
necessary member functions for the following:
i. Search the mobile number of given person.
ii. Search the person name of given mobile number.
iii. Search all person details of given city.
(Use function overloading)*/

#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    string pName;
    string city;
    int age;
    long long mNumber;

public:
    void setData()
    {
        cout << "Enter Person Name: ";
        cin >> pName;
        cout << "Enter Mobile Number: ";
        cin >> mNumber;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter City: ";
        cin >> city;
    }

    void display()
    {
        cout << pName << " " << mNumber << " " << age << " " << city << endl;
    }

    // Function overloading for searching mobile number by person name
    long long searchMobile(const string &name)
    {
        if (name == pName)
        {
            return mNumber;
        }
        else
        {
            cout << "Person not found" << endl;
            return -1;
        }
    }

    // Function overloading for searching person name by mobile number
    string searchName(const long long &num)
    {
        if (num == mNumber)
        {
            return pName;
        }
        else
        {
            cout << "Person not found" << endl;
            return "";
        }
    }

    // Function overloading for searching person details by city
    void searchPerson(const string &cityName)
    {
        if (cityName == city)
        {
            display();
        }
        else
        {
            cout << "Person not found" << endl;
        }
    }
};

int main()
{
    Person p;
    p.setData();

    string nameToSearch;
    long long numToSearch;
    string cityToSearch;

    cout << "Enter person name to search mobile number: ";
    cin >> nameToSearch;
    long long mobileNum = p.searchMobile(nameToSearch);
    if (mobileNum != -1)
    {
        cout << "Mobile number: " << mobileNum << endl;
    }

    cout << "Enter mobile number to search person name: ";
    cin >> numToSearch;
    string searchedName = p.searchName(numToSearch);
    if (!searchedName.empty())
    {
        cout << "Name: " << searchedName << endl;
    }

    cout << "Enter city to search person details: ";
    cin >> cityToSearch;
    p.searchPerson(cityToSearch);

    return 0;
}
