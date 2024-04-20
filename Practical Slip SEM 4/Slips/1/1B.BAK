#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <ctype.h>
#include<string.h>

class MyFile
{
public:
	char name[100];
	ofstream out;
	ifstream in;

	MyFile(){};
	MyFile(char *str)
	{
		strcpy(name, str);
	}

	void display()
	{
		char ch;
		in.open(name);

		while ((ch = in.get()) != EOF)
		{
			cout << ch;
		}
		in.close();
	}

	void operator+(MyFile &f2)
	{
		in.open(name);
		f2.in.open(f2.name);
		MyFile r("C:\\TURBOC3\\BIN\\Slips\\1\\f3.txt"); // add f3
		r.out.open(r.name);

		char ch;
		while ((ch = in.get()) != EOF)
		{
			r.out << ch;
		}

		while ((ch = f2.in.get()) != EOF)
		{
			r.out << ch;
		}

		in.close();
		f2.in.close();
		r.out.close();
	}

	void operator!()
	{
		in.open(name);
		MyFile r("C:\\TURBOC3\\BIN\\Slips\\1\\ans.txt"); // add ans
		r.out.open(r.name);
		char ch;
		int c = 1;

		while ((ch = in.get()) != EOF)
		{
			if (c % 2 == 0)
			{
				if(isupper(ch)){
					r.out << char(tolower(ch));
				}
				else{
					r.out << char(toupper(ch));
				}
			}
			else
			{
				r.out << ch;
			}
			c++;
		}
		in.close();
		r.out.close();
	}
};

int main()
{
	clrscr();
	MyFile f1("C:\\TURBOC3\\BIN\\Slips\\1\\f1.txt");
	MyFile f2("C:\\TURBOC3\\BIN\\Slips\\1\\f2.txt");
	MyFile f3("C:\\TURBOC3\\BIN\\Slips\\1\\f3.txt");
	MyFile ans("C:\\TURBOC3\\BIN\\Slips\\1\\ans.txt");

	cout << "Content After concatination of f1 and f2 : " << endl;
	f1 + f2;
	f3.display();

	cout << "\nContent after changing Case : " << endl;
	!f3;
	ans.display();
	getch();
	return 0;
}
