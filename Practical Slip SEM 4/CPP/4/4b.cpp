/*) Write a C++ program to create a base class Employee (Emp-code, name, salary). Derive two classes as Fulltime (daily_wages, number_of_days)
and Parttime (number_of_working_hours, hourly_wages).
Write a menu driven program to perform following functions:
1. Accept the details of 'n' employees and calculate the salary.
2. Display the details of 'n' employees.
3. Display the details of employee having maximum salary for both types of employees.*/

#include <iostream>
#include <vector>
using namespace std;

class Employee
{
protected:
    int empCode;
    string name;
    float salary;

public:
    virtual void setData() = 0;
    virtual void calculateSalary() = 0;
    void display()
    {
        cout << "Employee Code: " << empCode << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: $" << salary << endl;
    }
};

class Fulltime : public Employee
{
    int dailyWages, noOfDays;

public:
    void setData() override
    {
        cout << "Enter Employee Code: ";
        cin >> empCode;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Daily Wages: $";
        cin >> dailyWages;
        cout << "Enter Number of Days: ";
        cin >> noOfDays;
    }

    void calculateSalary() override
    {
        salary = dailyWages * noOfDays;
    }
};

class Parttime : public Employee
{
    int noOfWorkingHours;
    float hourlyWages;

public:
    void setData() override
    {
        cout << "Enter Employee Code: ";
        cin >> empCode;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Number of Working Hours: ";
        cin >> noOfWorkingHours;
        cout << "Enter Hourly Wages: $";
        cin >> hourlyWages;
    }

    void calculateSalary() override
    {
        salary = noOfWorkingHours * hourlyWages;
    }
};

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    vector<Employee *> employees(n);

    for (int i = 0; i < n; i++)
    {
        int type;
        cout << "Enter 1 for Fulltime and 2 for Parttime: ";
        cin >> type;

        if (type == 1)
        {
            employees[i] = new Fulltime();
        }
        else if (type == 2)
        {
            employees[i] = new Parttime();
        }
        else
        {
            cout << "Invalid employee type!" << endl;
            i--; // Decrement i to re-enter details for this employee
            continue;
        }

        employees[i]->setData();
        employees[i]->calculateSalary();
    }

    for (int i = 0; i < n; i++)
    {
        employees[i]->display();
    }

    // Free memory allocated for Employee objects
    for (auto emp : employees)
    {
        delete emp;
    }

    return 0;
}
