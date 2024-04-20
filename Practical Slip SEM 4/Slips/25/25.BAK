#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

inline float mean(int n1, int n2, int n3){
	float m = (n1+n2+n3) / 3;
	return m;
}

inline float mode(int n1, int n2, int n3){
	if(n1 == n2 && n2 == n3){
		return n1;
	}else if(n1 == n2 || n2 == n3){
		return n2;
	}else{
		return -1;
	}
}

inline float median(int n1, int n2, int n3){
	int arr[3] = {n1, n2, n3};

	for(int i=0; i<3; i++){
		for(int j=i+1; j<3-1; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr[1];
}

int main(){
	clrscr();
	int n1, n2, n3;

	cout << "Enter Three Number : ";
	cin >> n1 >> n2 >> n3;
	int ans;
	ans = mean(n1, n2, n3);
	cout << "Mean : " << ans << endl;

	ans = mode(n1, n2, n3);
	if(ans == -1){
		cout << "Mode Not Found" << endl;
	}else{
		cout << "Mode : " << ans << endl;
	}

	ans = median(n1, n2, n3);
	cout << "Median : " << ans << endl;
	getch();
	return 0;
}