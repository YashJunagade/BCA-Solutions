#include<iostream.h>
#include<conio.h>

class Number{
public :
	static int cnt;
	void display(){
		cout << "Function Called : " << cnt << endl;
		cnt++;
	}
};

int Number::cnt = 1;

int main(){
	clrscr();
	Number n;
	n.display();
	n.display();
	getch();
	return 0;
}