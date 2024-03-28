/*Create a base class Travels with data members T_no, Company_Name. Derive a class Route with data members Route id, Source, and Destination
from Travels class. Also derive a class Reservation with data members Number of Seats, Travels Class, Fare, and Travel Date from Route.
Write a C++ program to perform following necessary member functions:
i. Accept details of 'n' reservations.
ii. Display details of all reservations.
iii. Display reservation details of a specified Date.*/

#include <bits/stdc++.h>
using namespace std;

class Travels
{
    int tno;
    string cname;

public:
    void setTravels()
    {
        cout << "Enter Travel Number: ";
        cin >> tno;
        cout << "Enter Company Name: ";
        cin >> cname;
    }

    void displayTravels()
    {
        cout << "Travel Number: " << tno << endl;
        cout << "Company Name: " << cname << endl;
    }
};

class Route : public Travels
{
    int rid;
    string source, destination;

public:
    void setRoute()
    {
        setTravels();
        cout << "Enter Route ID: ";
        cin >> rid;
        cout << "Enter Source: ";
        cin >> source;
        cout << "Enter Destination: ";
        cin >> destination;
    }

    void displayRoute()
    {
        displayTravels();
        cout << "Route ID: " << rid << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
    }
};

class Reservation : public Route
{
public:
    int nseats;
    string tclass;
    int tdate;
    float fare;

    void setData()
    {
        setRoute();
        cout << "Enter Number of Seats: ";
        cin >> nseats;
        cout << "Enter Travel Class: ";
        cin >> tclass;
        cout << "Enter Travel Date: ";
        cin >> tdate;
        cout << "Enter Fare: ";
        cin >> fare;
    }

    void display()
    {
        displayRoute();
        cout << "Number of Seats: " << nseats << endl;
        cout << "Travel Class: " << tclass << endl;
        cout << "Travel Date: " << tdate << endl;
        cout << "Fare: " << fare << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of reservations: ";
    cin >> n;

    Reservation r[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for reservation " << i + 1 << ": " << endl;
        r[i].setData();
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Details of reservation " << i + 1 << ": " << endl;
        r[i].display();
    }

    int date;
    cout << "Enter travel date: ";
    cin >> date;

    for (int i = 0; i < n; i++)
    {
        if (date == r[i].tdate)
            r[i].display();
        else
            cout << "no data found";
    }
    return 0;
}