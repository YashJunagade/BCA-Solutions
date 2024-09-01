/*Design two base classes Student (S_id, Name, Class) and Competition (C_id, C_Name). Derive a class Stud_Comp(Rank) from it.
Write a menu driven program to perform following functions:
i. Accept information.
ii. Display information.
iii. Display Student Details in the ascending order of Rank of a specified competition.
(Use array of objects)*/

#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int sid;
    string name, className;

    void setStudent()
    {
        cout << "Enter Student ID: ";
        cin >> sid;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Class Name: ";
        getline(cin, className);
    }

    void displayStudent() const
    {
        cout << "Student ID: " << sid << ", Name: " << name << ", Class: " << className << endl;
    }
};

class Competition
{
public:
    int cid;
    string cname;

    void setCompetition()
    {
        cout << "Enter Competition ID: ";
        cin >> cid;
        cout << "Enter Competition Name: ";
        cin.ignore();
        getline(cin, cname);
    }

    void displayCompetition() const
    {
        cout << "Competition ID: " << cid << ", Name: " << cname << endl;
    }
};

class Stud_Comp : public Student, public Competition
{
public:
    int rank;

    void setData()
    {
        setStudent();
        setCompetition();
        cout << "Enter Rank: ";
        cin >> rank;
    }

    void display() const
    {
        displayStudent();
        displayCompetition();
        cout << "Rank: " << rank << endl;
    }
};

void sortByRank(Stud_Comp arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].rank > arr[j + 1].rank)
            {
                Stud_Comp temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, choice, cid;
    cout << "Enter number of students: ";
    cin >> n;
    Stud_Comp *sc = new Stud_Comp[n];

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Accept Data" << endl;
        cout << "2. Display Data" << endl;
        cout << "3. Display Student Details in Ascending Order of Rank for a Specific Competition" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter details for student " << i + 1 << ":" << endl;
                sc[i].setData();
            }
            break;
        case 2:
            cout << "\nDisplaying Student Data:" << endl;
            for (int i = 0; i < n; i++)
            {
                sc[i].display();
            }
            break;
        case 3:
            cout << "\nEnter Competition ID to display student details in ascending order of rank: ";
            cin >> cid;

            sortByRank(sc, n);

            cout << "\nStudent Details in Ascending Order of Rank for Competition ID " << cid << ":" << endl;
            for (int i = 0; i < n; i++)
            {
                if (sc[i].cid == cid)
                {
                    sc[i].display();
                }
            }
            break;
        case 4:
            cout << "\nExiting program..." << endl;
            break;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    delete[] sc;
    return 0;
}
