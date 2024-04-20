#include<iostream.h>
#include<conio.h>

class College{
public :
	int id, year;
	char name[100], uname[100];

	friend void operator>>(istream &in, College &c){
		cout << "Enter College Id : ";
		in >> c.id;
		cout << "Enter College Name : ";
		in >> c.name;
		cout << "Enter Establishment Year : ";
		in >> c.year;
		cout << "Enter University Name : ";
		in >> c.uname;
	}

	friend void operator<<(ostream &out, College &c){
		out << "College Id : " << c.id << endl;
		out << "College Name : " << c.name << endl;
		out << "Establishment Year : " << c.year << endl;
		out << "University Name : " << c.uname << endl;
	}
};

int main(){
	clrscr();
	College c;
	cout << "Enter College Details " << endl;
	cin >> c;
	cout << "Display College Details " << endl;
	cout << c;
	getch();
	return 0;
}