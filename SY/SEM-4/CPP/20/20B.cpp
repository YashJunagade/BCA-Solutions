/*Create a C++ class for inventory of Mobiles with data members Model, Mobile Company, Color, Price and Quantity. Mobile can be sold,
if stock is available, otherwise purchase will be made. Write necessary member functions for the following:
i. To accept mobile details from user.
ii. To sale a mobile. (Sale contains Mobile details & number of mobiles to be sold.)
iii. To Purchase a Mobile. (Purchase contains Mobile details & number of mobiles to be purchased)*/

#include <bits/stdc++.h>
using namespace std;

class Mobile
{
private:
    string model, company, color;
    int price, quantity;

public:
    static int stock; // Define static variable stock

    void setData()
    {
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Company: ";
        cin >> company;
        cout << "Enter Color: ";
        cin >> color;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;   // Store quantity in instance variable
        stock += quantity; // Add quantity to stock
    }

    void display()
    {
        cout << "Model: " << model << endl;
        cout << "Company: " << company << endl;
        cout << "Color: " << color << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    void purchase(int purchase)
    {
        if (purchase > 0 && purchase <= stock)
        {
            stock -= purchase;
            cout << "Purchase Successful" << endl;
        }
        else
        {
            cout << "Purchase Failed: Stock not available" << endl;
        }
    }

    void sale(int sale)
    {
        if (sale > 0 && sale <= stock)
        {
            stock -= sale;
            cout << "Sale Successful" << endl;
        }
        else
        {
            cout << "Sale Failed: Stock not available" << endl;
        }
    }
};

// Initialize static member stock
int Mobile::stock = 0;

int main()
{
    Mobile m1;
    m1.setData(); // Accept mobile details
    m1.display(); // Display mobile details

    int purchaseQuantity, saleQuantity;
    cout << "Enter quantity to purchase: ";
    cin >> purchaseQuantity;
    m1.purchase(purchaseQuantity); // Purchase mobile

    cout << "Enter quantity to sell: ";
    cin >> saleQuantity;
    m1.sale(saleQuantity); // Sell mobile

    return 0;
}
