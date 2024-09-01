/*Write a C++ program to create a class Product with data members Product_id, Product_Name, Qty, Price.
Write member functions to accept and display Product information also display number of objects created
for Product class. (Use Static data member and Static member function) */

#include <bits/stdc++.h>
using namespace std;

class Product
{
    int pId, qty;
    string pName;
    float price;
    static int counter;

public:
    Product()
    {
        cout << "Enter Product Id: ";
        cin >> pId;
        cout << "Enter Product Name: ";
        cin.ignore();
        getline(cin, pName);
        cout << "Enter Quantity: ";
        cin >> qty;
        cout << "Enter Price: ";
        cin >> price;

        counter++;
    }

    void display()
    {
        cout << "Product Id: " << pId << endl;
        cout << "Product Name: " << pName << endl;
        cout << "Quantity: " << qty << endl;
        cout << "Price: " << price << endl;
    }

    static void displayCounter()
    {
        cout << "Counter : " << counter;
    }
};

int Product::counter = 0;

int main()
{
    Product p1;
    Product p2;
    p1.display();
    p2.display();
    Product::displayCounter();

    return 0;
}