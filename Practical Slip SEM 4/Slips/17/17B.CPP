#include<iostream.h>
#include<conio.h>

class Student{
public :
	int sid;
	char name[100], c[100];

	void setStudent(){
		cout << "Enter Student Id : ";
		cin >> sid;
		cout << "Enter Student Name : ";
		cin >> name;
		cout << "Enter Student Class : ";
		cin >> c;
	}

	void displayStudent(){
		cout << "Student Id : " << sid << endl;
		cout << "Student Name : " << name << endl;
		cout << "Class : " << c << endl;
	}

};

class Competition{
public :
	int cid;
	char cname[100];

	void setComp(){
		cout << "Ente Competition Id : ";
		cin >> cid;
		cout << "Enter Competition Name : ";
		cin >> cname;
	}

	void displayComp(){
		cout << "Competition Id : " << cid << endl;
		cout << "Competition Name : " << cname << endl;
	}
};

class StudComp : public Student, public Competition{
public :
	int rank;
	void setStudComp(){
		setStudent();
		setComp();
		cout << "Enter Rank : ";
		cin >> rank;
	}

	void displayStudComp(){
		displayStudent();
		displayComp();
		cout << "Rank : " << rank << endl;
	}

	void sort(StudComp &i, StudComp &j){
		if(i.rank > j.rank){
			StudComp temp = i;
			i = j;
			j = temp;
		}
	}
};


int main(){
	clrscr();
	int n, i, choice, cnt = 0;
	StudComp *r;
	cout << "Enter Total no of Students : ";
	cin >> n;

	r = new StudComp[n];

	do{

		cout << "\n1.Accept Student Info "
			<< "\n2.Display Student Info "
			<< "\n3.Sort Student details in ascending order by rank "
			<< "\n4.Exit"
			<< "\nEnter choice : ";
		cin >> choice;

		switch(choice){
			case 1 :
				r[cnt].setStudComp();
				cnt++;
				break;
			case 2 :
				cout << "Displaying details of student : " << endl;
				for(i=0; i<cnt; i++){
					cout << "student " << i+1 << " details : " << endl;
					r[i].displayStudComp();
				}
				break;
			case 3 :
				for(i=0; i<cnt; i++){
					for(int j=i+1; j<cnt; j++){
						r[i].sort(r[i], r[j]);
					}
				}
				cout << "Student Sorted By Rank Successfully " << endl;
				break;

			case 4 :
				cout << "Exiting...";
				break;
			default :
				cout << "Invalid Choice ";
		}
	}while(choice != 4);
	getch();
	return 0;
}