#include<iostream.h>
#include<conio.h>

void volume(float r, float h){
	float v = 3.14 * r * r * h;
	cout << "Volume Of Cylinder : " << v << endl;
}

void volume(float r){
	float v = ((4.0) / (3.0)) * 3.14 * r * r * r;
	cout << "Volume of Cone : " << v << endl;
}

void volumeSphere(float r, float h){
	float v = ((1.0) / (3.0)) * 3.14 * r * r * h;
	cout << "Volume of Sphere : " << v << endl;

}


int main(){
	clrscr();
	float r, h;
	cout << "Enter Radius and Height for Cylinder : ";
	cin >> r >> h;
	volume(r, h);

	cout << "Enter Radius for Cone : ";
	cin >> r;
	volume(r);

	cout << "Enter Radius and Height for Shpere : ";
	cin >> r >> h;
	volumeSphere(r, h);
	getch();
	return 0;
}