#include<iostream.h>
#include<conio.h>

class Cuboid{
public :
	float l, b, h;
	void setValues(float l, float b, float h){
		this->l = l;
		this->b = b;
		this->h = h;
	}

	void getValues(){
		cout << "Length : " << l << endl;
		cout << "Breadth : " << b << endl;
		cout << "Height : " << h << endl;
	}

	inline float volume(){
		float v = l * b * h;
		return v;
	}

	inline float surfaceArea(){
		float sa = (2 * ((l * b) + (b * h) + (l * h)));
		return sa;
	}
};

int main(){
	clrscr();
	float l, b, h;
	cout << "Enter Length, Breadth and Height : " ;
	cin >> l >> b >> h;

	Cuboid c;
	c.setValues(l, b, h);
	c.getValues();

	cout << "Volume of Cuboid : " << c.volume() << endl;
	cout << "Surface Area : " << c.surfaceArea() << endl;

	getch();
	return 0;
}