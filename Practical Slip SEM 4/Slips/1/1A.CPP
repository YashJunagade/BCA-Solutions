#include<iostream.h>
#include<conio.h>


inline void minMax(int n1, int n2){
	int maxNum = (n1 > n2) ? n1 : n2;
	int minNum = (n1 < n2) ? n1 : n2;

	cout << "Maximum : "  << maxNum <<endl;
	cout << "Minimum : " << minNum << endl;

}

int main(){
	clrscr();
	int n1, n2;
	cout << "Enter Two Number : ";
	cin >> n1 >> n2;
	minMax(n1, n2);
	getch();
	return 0;
}