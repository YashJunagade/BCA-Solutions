#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	clrscr();
	int i;
	ofstream ofile("C:\\TURBOC3\\BIN\\Slips\\3\\odd.txt", ios::app);
	ofstream efile("C:\\TURBOC3\\BIN\\Slips\\3\\even.txt", ios::app);

	for (i = 0; i < argc; i++)
	{
		int num = atoi(argv[i]);

		if (num % 2 == 0)
		{
			efile << num << " ";
		}
		else
		{
			ofile << num << " ";
		}
	}

	cout << "File sorted successfully ";
	ofile.close();
	efile.close();
	getch();
	return 0;
}