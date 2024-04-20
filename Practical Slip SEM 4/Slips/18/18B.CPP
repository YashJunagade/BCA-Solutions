#include<iostream.h>
#include<conio.h>

class MyArray{
public :
	int *arr, size;
	MyArray(int n){
		size = n;
		arr = new int[size];
	}

	void setArray(){
		for(int i =0; i<size; i++){
			cout << "Enter " << i+1 << " element : ";
			cin >> arr[i];
		}
	}

	void displayArray(){
		cout << "Array : ";
		for(int i=0; i<size; i++){
			cout << arr[i] << " ";
		}
	}

	void operator-(){
		MyArray ans(size);

		for(int i=0; i<size; i++){
			ans.arr[i] = arr[size-i-1];
		}

		ans.displayArray();
	}

	MyArray operator+(int n){
		MyArray ans(size);

		for(int i=0; i<size; i++){
			ans.arr[i] = arr[i] + n;
		}

		return ans;
	}
};

int main(){
	clrscr();
	int n, num;
	cout << "Enter size of array : ";
	cin >> n;
	MyArray a(n);
	a.setArray();
	a.displayArray();

	cout << "\nReverse Of an Array : " << endl;
	-a;

	cout << "\nEnter Constant Number : ";
	cin >> num;
	cout << "\nArray after adding constant : " << endl;
	MyArray a2(n);
	a2 = a + n;
	a2.displayArray();

	getch();
	return 0;
}