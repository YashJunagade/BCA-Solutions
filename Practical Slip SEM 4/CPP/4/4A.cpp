/*Write a C++ program to accept Worker information Worker_Name, No_of_Hours_worked, Pay_Rate and Salary.
Write necessary functions to calculate and display the salary of Worker. (Use default value for Pay_Rate)*/
#include <iostream>
#include <string>
using namespace std;

class Worker
{
private:
    int no_of_hours_worked;
    double salary, payRate;
    string wName;

public:
    Worker(int nohw, string wn, double pr = 50.0)
    {
        no_of_hours_worked = nohw;
        payRate = pr;
        wName = wn;
    }

    void display()
    {
        salary = no_of_hours_worked * payRate;
        cout << "Worker Name : " << wName << endl;
        cout << "Number of Hours Worked : " << no_of_hours_worked << endl;
        cout << "Pay Rate : " << payRate << endl;
        cout << "Salary : " << salary << endl;
    }
};

int main()
{
    string wn;
    int n;
    double pr;

    cout << "Enter name of worker : ";
    cin >> wn;
    cout << "Enter how many hours worker worked : ";
    cin >> n;

    Worker W1(n, wn);
    W1.display();

    return 0;
}
