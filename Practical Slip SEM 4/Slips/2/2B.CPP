#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <fstream.h>

class Movie
{
public:
	char name[100], year[5], dname[100];
	float budget;
	static int count;

	void setMovie()
	{
		cout << "Enter Movie Name : ";
		cin >> name;
		cout << "Enter Release Year : ";
		cin >> year;
		cout << "Enter Director Name ; ";
		cin >> dname;
		cout << "Enter Budget : ";
		cin >> budget;

		ofstream in;
		in.open("C:\\TURBOC3\\BIN\\Slips\\2\\movie.txt", ios::app);
		in << "Movie Name : " << name << endl;
		in << "Release Year : " << year << endl;
		in << "Director Name : " << dname << endl;
		in << "Budget : " << budget << endl;

		count++;
		in.close();
	}

	void display()
	{
		ifstream out;
		out.open("C:\\TURBOC3\\BIN\\Slips\\2\\movie.txt");
		char ch;

		while ((ch = out.get()) != EOF)
		{
			cout << ch;
		}
		out.close();
	}

	static void displayCount()
	{
		cout << "Total Object Created : " << count << endl;
	}
};

int Movie::count = 0;

int main()
{
	clrscr();
	int n, i;

	Movie *m;
	m = new Movie[10];
	cout << "Enter Numbers of movies : ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Enter Details For Movie " << i + 1 << " : " << endl;
		m[i].setMovie();
	}

	cout << "Displaying Details Of Movies : " << endl;
	for (i = 0; i < n; i++)
	{
		cout << "Movie No : 1 " << endl;
		m[i].display();
	}

	Movie::displayCount();
	getch();
	return 0;
}