#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// using namespace std;

class Student
{
private:
	int rno;
	char sname[100];

public:
	void setStudent()
	{
		cout << "Enter Student Roll No : ";
		cin >> rno;
		cout << "Enter Student Name : ";
		cin >> sname;
	}

	void displayStudent()
	{
		cout << "Roll No : " << rno << endl;
		cout << "Student Name : " << sname << endl;
	}
};

class Theory : virtual protected Student
{
public:
	int m1, m2, m3, m4, m5;

	void setTheory()
	{
		setStudent();
		cout << "Enter marks of 5 subjects : ";
		cin >> m1 >> m2 >> m3 >> m4 >> m5;
	}

	void displayTheory()
	{
		displayStudent();
		cout << "Theory Subject Marks : " << endl;
		cout << "Marks 1 : " << m1 << endl;
		cout << "Marks 2 : " << m2 << endl;
		cout << "Marks 3 : " << m3 << endl;
		cout << "Marks 4 : " << m4 << endl;
		cout << "Marks 5 : " << m5 << endl;
	}
};

class Practical : virtual protected Student
{
public:
	int p1, p2;

	void setPractical()
	{
		cout << "Enter 2 Practical subjects Marks : ";
		cin >> p1 >> p2;
	}

	void displayPractical()
	{
		cout << "Marks of practical subject marks : " << endl;
		cout << "Practical 1 : " << p1 << endl;
		cout << "Practical 2 : " << p2 << endl;
	}
};

class Result : public Theory, public Practical
{
public:
	int totalmarks;
	char grade;

	void setResult()
	{
		setTheory();
		setPractical();
	}

	void displayResult()
	{
		displayTheory();
		displayPractical();
	}

	void calculate()
	{
		totalmarks = (m1 + m2 + m3 + m4 + m5) + (p1 + p2);

		float per = (float)totalmarks / 700 * 100;

		if (per >= 90)
		{
			grade = 'A';
		}
		else if (per >= 75)
		{
			grade = 'B';
		}
		else if (per >= 50)
		{
			grade = 'C';
		}
		else if (per >= 40)
		{
			grade = 'D';
		}
		else
		{
			grade = 'F';
		}

		cout << "Total Marks : " << totalmarks << endl;
		cout << "Percentage : " << per << endl;
		cout << "Grade : " << grade << endl;
	}
};

int main()
{
	clrscr();
	int n, i, choice, c = 0;
	Result r[10];

	do
	{
		cout << "1. Accept Student\n"
			 << "2. Display Student\n"
			 << "3. Calculate TotalMarks, Percentage, Grade \n"
			 << "4. Exit\n"
			 << "Enter choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			r[c].setResult();
			c++;
			break;
		case 2:
			for (i = 0; i < c; i++)
			{
				r[i].displayResult();
			}
			break;
		case 3:
			for (i = 0; i < c; i++)
			{
				r[i].calculate();
			}
			break;
		case 4:
			cout << "Thank You";
			exit(1);
			break;
		default:
			cout << "Invalid Choice : ";
		}
	} while (choice != 4);
	getch();
	return 0;
}
