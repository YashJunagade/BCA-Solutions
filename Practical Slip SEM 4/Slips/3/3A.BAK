#include<iostream.h>
#include<conio.h>

void callByReference(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	clrscr();
	int a, b;
	cout << "Enter Two Numbers : ";
	cin >> a >> b;

	cout << "Before Value Swap : " << a << " "<< b << endl;
	callByReference(a, b);
	cout << "After Value Swap : " << a << " " << b << endl;
	getch();
	return 0;
}