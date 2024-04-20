#include <iostream.h>
#include <conio.h>

class Number
{
	int num;
	Number(){};
	Number(int n)
	{
		num = n;
	}

	int operator++()
	{
		++num;
		return num;
	}

	int operator++(int)
	{
		num++;
		return this->num;
	}
};

int main()
{
	clrscr();
	int n;
	cout << "Enter Number : ";
	cin >> n;

	cout << "Pre Increment : " << ++n << endl;
	cout << "Post Increment : " << n++ << endl;
	getch();
	return 0;
}