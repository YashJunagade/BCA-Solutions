/*Write a C++ program to find volume of cylinder, cone and sphere. (Use function overloading).*/

#include <bits/stdc++.h>
using namespace std;
const float pi = 3.14;

void volume(float r, float h)
{
    float v = pi * r * r * h;
    cout << "Volume of Cylinder = " << v << endl;
}

void volume(float r)
{
    float v = (4.0 / 3.0) * pi * r * r * r;
    cout << "Volume of Sphere = " << v << endl;
}

void volume(float r, float h, string str)
{
    float v = (1.0 / 3.0) * pi * r * r * h;
    cout << "Volume of Cone = " << v << endl;
}

int main()
{
    int r, h;
    cout << "Enter radius and height of Cylinder : ";
    cin >> r >> h;
    volume(r, h);
    cout << "Enter radius and height of Cone : ";
    cin >> r >> h;
    volume(r, h, "cone");
    cout << "Enter radius of Sphere : ";
    cin >> r;
    volume(r);
    return 0;
}