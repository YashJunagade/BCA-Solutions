/*Create a C++ class Cuboid with data members length, breadth, and height. Write necessary member functions for the following:
i. void setvalues (float, float, float) to set values of data members.
ii. void getvalues() to display values of data members.
iii. float volume() to calculate and return the volume of cuboid.
iv. float surface_area() to calculate and return the surface area of cuboid.
(Use Inline function)*/

#include <bits/stdc++.h>
using namespace std;

class Cuboid
{
    float length, breadth, height;

public:
    void setvalues(float l, float b, float h)
    {
        length = l;
        breadth = b;
        height = h;
    }
    void getvalues()
    {
        cout << "Length = " << length << endl;
        cout << "Breadth = " << breadth << endl;
        cout << "Height = " << height << endl;
    }
    inline float volume()
    {
        return length * breadth * height;
    }
    inline float surface_area()
    {
        return 2 * ((length * breadth) + (length * height) + (breadth * height));
    }
};

int main()
{
    Cuboid c;
    int l, b, h;
    cout << "Enter length, breadth and height : ";
    cin >> l >> b >> h;
    c.setvalues(l, b, h);
    c.getvalues();
    cout << "Volume = " << c.volume() << endl;
    cout << "Surface Area = " << c.surface_area() << endl;

    return 0;
}