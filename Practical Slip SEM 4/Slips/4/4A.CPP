#include<iostream.h>
#include<conio.h>

float calculate(int nohw, float salary, float prate = 53.0){
	int ans = salary + (nohw * prate);
	return ans;
}

int main(){
	clrscr();
	char wname[100];
	int nohw;
	float salary, prate;

	cout << "Enter Worker Name : ";
	cin >> wname;
	cout << "Enter No Of Hours Worked : ";
	cin >> nohw;
	cout << "Enter Basic Salary : ";
	cin >> salary;

	float ans = calculate(nohw, salary);
	cout << "Worker Name : " << wname << endl;
	cout << "No of Hours Worked : " << nohw << endl;
	cout << "Basic Salary : " << salary << endl;
	cout << "Salary : " << ans << endl;
	getch();
	return 0;
}