#include<iostream.h>
#include<conio.h>

class Employee{
public :
	int ecode;
	char name[100];
	float salary;

	void setEmployee(){
		cout << "Enter Employee Code : ";
		cin >> ecode;
		cout << "Enter Employee Name : ";
		cin >> name;
		cout << "Enter Salary : ";
		cin >> salary;
	}

	void displayEmployee(){
		cout << "Employee Code : " << ecode << endl;
		cout << "Employee Name : " << name << endl;
		cout << "Salary : " << salary << endl;
	}
};

class FullTime : public Employee{
public :
	int dwages, nod, totalFullTime;
	void setFullTime(){
		setEmployee();
		cout << "Enter Daily Wages : ";
		cin >> dwages;
		cout << "Enter No of days worked : ";
		cin >> nod;
	}

	void displayFullTime(){
		displayEmployee();
		cout << "Daily Wages : " << dwages << endl;
		cout << "No Of Days Worked : " << nod << endl;
	}

	float calculateFullTime(){
		totalFullTime = (dwages * nod) + salary;
		return totalFullTime;
	}
};

class PartTime : public Employee{
public :
	int nohw, hwages, totalPartTime;
	void setPartTime(){
		setEmployee();
		cout << "No of hours worked : ";
		cin >> nohw;
		cout << "Enter Hourly Wages : ";
		cin >> hwages;
	}

	void displayPartTime(){
		displayEmployee();
		cout << "No of hours worked : " << nohw << endl;
		cout << "Hourly Wages : " << hwages << endl;
	}

	float calculatePartTime(){
		totalPartTime = (nohw * hwages) + salary;
		return totalPartTime;
	}
};

int main(){
	clrscr();
	PartTime p[10];
	FullTime f[10];
	int i, choice, n;
	do{
		cout << "\n1.Accept PartTime Employee & Calculate Salary "
			<< "\n2.Accept FullTime Employee & Calculate Salary "
			<< "\n3.Display PartTime Employee "
			<< "\n4.Display FullTime Employee "
			<< "\n5.Maximum Salary Employee : "
			<< "\n6.Exit"
			<< "\nEnter Choice : ";
		cin >> choice;

		switch(choice){
			case 1 :
				cout << "Enter Total Number Of PartTime Employee : ";
				cin >> n;
				for(i=0; i<n; i++){
					cout << "Enter Details For Employee " << i+1 << " : " << endl;
					p[i].setPartTime();
					p[i].calculatePartTime();
				}
				break;
			case 2 :
				cout << "Enter Total Number Of FullTime Employee : ";
				cin >> n;
				for(i=0; i<n; i++){
				       cout << "Enter Details For Employee " << i+1 << " : " << endl;
				       f[i].setFullTime();
				       f[i].calculateFullTime();
				}
				break;
			case 3 :
				cout << "Displaying Details of Parttime Employee : " << endl;
				for(i=0; i<n; i++){
					cout << "PartTime Employee " << i+1 << " : " << endl;
					p[i].displayPartTime();
				}
				break;

			case 4 :
				cout << "Displaying Details of Fulltime Employee : " << endl;
				for(i=0; i<n; i++){
					cout << "FullTime Employee " << i+1 << " : " << endl;
					p[i].displayFullTime();
				}
				break;
			case 5 :
				int maxP = 0, maxF =0, mPsalary = p[0].calculatePartTime(), mFsalary = f[0].calculateFullTime();
				for(i=1; i<n; i++){
					if(mPsalary < p[i].calculatePartTime()){
						maxP = i;
					}

					if(mFsalary < f[i].calculateFullTime()){
						maxF = i;
					}
				}

				cout << "Displaying Maximum Employee : " << endl;
				if(p[maxP].calculatePartTime() > f[maxF].calculateFullTime()){
					p[maxP].displayPartTime();
				}
				else{
					f[maxF].displayFullTime();
				}
				break;
			case 6 :
				cout << "Thank You";
				break;
			default :
				cout << "Invalid Choice ";
		}
	}while(choice != 6);
	getch();
	return 0;
}