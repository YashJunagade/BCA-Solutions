#include<iostream.h>
#include<conio.h>

class MyArray{
public :
	int n, *arr;
	MyArray(int size){
		n = size;
		arr = new int[n];

		for(int i=0; i<n; i++){
			cout << "Enter " << i+1 << " element : ";
			cin >> arr[i];
		}
	}

	void displayArray(){
		cout << "Array Element Are : " ;
		for(int i=0; i<n; i++){
			cout << arr[i] <<  " ";
		}
	}

	void sum(){
		int sum =0;
		for(int i=0; i<n; i++){
			sum += arr[i];
		}
		cout << "Sum Of Array : " << sum << endl;
	}
};

int main(){
	clrscr();
	int size;
	cout << "Enter Size of array : ";
	cin >> size;

	MyArray a(size);
	a.displayArray();
	cout << endl;
	a.sum();
	getch();
	return 0;
}