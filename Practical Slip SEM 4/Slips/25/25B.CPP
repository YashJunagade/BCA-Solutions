#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <ctype.h>

int main()
{
	clrscr();
	ifstream cfile("C:\\TURBOC3\\BIN\\Slips\\25\\sample.txt");
	ofstream ufile("C:\\TURBOC3\\BIN\\Slips\\25\\upper.txt");
	ofstream lfile("C:\\TURBOC3\\BIN\\Slips\\25\\lower.txt");
	ofstream dfile("C:\\TURBOC3\\BIN\\Slips\\25\\digit.txt");
	ofstream ofile("C:\\TURBOC3\\BIN\\Slips\\25\\other.txt");

	char ch;
	while ((ch = cfile.get()) != EOF)
	{
		if (isdigit(ch))
		{
			dfile << ch;
		}
		else if (isupper(ch))
		{
			ufile << ch;
		}
		else if (islower(ch))
		{
			lfile << ch;
		}
		else
		{
			ofile << ch;
		}
	}

	cfile.close();
	ufile.close();
	lfile.close();
	dfile.close();
	ofile.close();

	cout << "Character Are Stored Successfully";
	getch();
	return 0;
}