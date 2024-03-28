/*Write a C++ class Seller (S_Name, Product_name, Sales_Quantity, Target_Quantity, Month,
Commission). Each salesman deals with a separate product and is assigned a target for a month. At the end of the month his monthly
sales is compared with target and commission is calculated as follows:
If Sales_Quantity>Target_Quantity then commission is 25% of extra sales made + 10% of target.
If Sales_Quantity = Target_Quantity then commission is 10% of target.
Otherwise commission is zero.
Display salesman information along with commission obtained. (Use array of objects) */

#include <bits/stdc++.h>
using namespace std;

class Seller
{
    int qyt, tqyt, month, commission;
    string pname, sname;

public:
    void setData()
    {

        cout << "Enter Salesman Name: ";
        cin >> sname;
        cout << "Enter Product Name: ";
        cin >> pname;
        cout << "Enter Sales Quantity: ";
        cin >> qyt;
        cout << "Enter Target Quantity: ";
        cin >> tqyt;
        cout << "Enter Month: ";
        cin >> month;
    }

    void calculate()
    {
        if (qyt > tqyt)
            commission = 0.25 * qyt + 0.1 * tqyt;
        else if (qyt == tqyt)
            commission = 0.1 * tqyt;
        else
            commission = 0;
    }

    void display()
    {
        cout << "Salesman Name: " << sname << endl;
        cout << "Product Name: " << pname << endl;
        cout << "Sales Quantity: " << qyt << endl;
        cout << "Target Quantity: " << tqyt << endl;
        cout << "Month: " << month << endl;
        cout << "Commission: " << commission << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of salesmen: ";
    cin >> n;

    Seller *s = new Seller[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for salesman " << i + 1 << ": " << endl;
        s[i].setData();
        s[i].calculate();
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Details of seller " << i + 1 << " : " << endl;
        s[i].display();
    }
    return 0;
}