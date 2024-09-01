/*Create a base class Student with data members Roll No, Name. Derives two classes from it,
class Theory with data members M1, M2, M3, M4 and class Practical with data members P1, P2.
Class Result(Total Marks, Percentage, Grade) inherits both Theory and Practical classes.
(Use concept of Virtual Base Class and protected access specifiers)
Write a C++ menu driven program to perform the following functions:
i. Accept Student Information
ii. Display Student Information
iii. Calculate Total_marks, Percentage and Grade.*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    int rollNo;
    string name;

public:
    void setStudent()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore(); // Ignore newline character
        getline(cin, name);
    }
};

class Theory : virtual protected Student
{
protected:
    int m1, m2, m3, m4;

public:
    void setTheoryMarks()
    {
        cout << "Enter Theory Marks of 4 subjects: ";
        cin >> m1 >> m2 >> m3 >> m4;
    }
};

class Practical : virtual protected Student
{
protected:
    int p1, p2;

public:
    void setPracticalMarks()
    {
        cout << "Enter Practical Marks of 2 subjects: ";
        cin >> p1 >> p2;
    }
};

class Result : public Theory, public Practical
{
protected:
    int totalMarks;
    float percentage;
    char grade;

public:
    void calculateResult()
    {
        totalMarks = m1 + m2 + m3 + m4 + p1 + p2;
        percentage = static_cast<float>(totalMarks) / 6.0;

        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 80)
            grade = 'B';
        else if (percentage >= 70)
            grade = 'C';
        else if (percentage >= 60)
            grade = 'D';
        else
            grade = 'F';
    }

    void setData()
    {
        setStudent();
    }
    void displayResult()
    {
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Result *students = new Result[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for student " << i + 1 << ":" << endl;
        students[i].setData();
        students[i].setTheoryMarks();
        students[i].setPracticalMarks();
        students[i].calculateResult();
    }

    cout << "\nResults:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\nDetails for student " << i + 1 << ":" << endl;
        students[i].displayResult();
    }

    delete[] students;
    return 0;
}
