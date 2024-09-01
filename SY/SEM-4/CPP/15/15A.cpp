/*Create a C++ class Fraction with data members Numerator and Denominator.
Write a C++ program to calculate and display sum of two fractions. (Use Constructor)*/

#include <iostream>
using namespace std;

class Fraction
{
    int numerator, denominator;

public:
    Fraction(int n, int d) : numerator(n), denominator(d) {}
    Fraction() : numerator(0), denominator(1) {} // Default constructor

    void display()
    {
        cout << numerator << "/" << denominator << endl;
    }

    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
};

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    Fraction f3;
    f3.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f3.denominator = f1.denominator * f2.denominator;

    return f3;
}

int main()
{
    int n1, d1, n2, d2;
    cout << "Enter numerator and denominator of first fraction : ";
    cin >> n1 >> d1;
    cout << "Enter numerator and denominator of second fraction : ";
    cin >> n2 >> d2;

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);
    Fraction f3 = f1 + f2;

    // Display the original fractions
    cout << "First fraction: ";
    f1.display();
    cout << "Second fraction: ";
    f2.display();
    cout << "Addition of two fraction : " << endl;
    f3.display();
    return 0;
}
