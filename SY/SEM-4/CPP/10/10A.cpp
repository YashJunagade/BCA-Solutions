/*Write a C++ program to create a class Account with data members Acc_number, Acc_type and Balance.
Write member functions to accept and display 'n' account details. (Use dynamic memory allocation)*/

#include <bits/stdc++.h>
using namespace std;

class Account
{
    int accNo;
    string accType;
    double balance;

public:
    void setData()
    {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Account Type: ";
        cin >> accType;
        cout << "Enter Balance: ";
        cin >> balance;
    }
    void getData()
    {
        cout << "Account Number : " << accNo;
        cout << "\nAccount Type : " << accType;
        cout << "\nBalance : " << balance << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;
    Account *a;
    a = new Account[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter account details for " << i + 1 << " account: " << endl;
        a[i].setData();
    }

    for (int i = 0; i < n; i++)
    {
        cout << "----------Account Detail ----------" << endl;
        a[i].getData();
    }

    return 0;
}