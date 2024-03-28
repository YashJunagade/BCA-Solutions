/*Create a C++ class City with data members City_code, City_name, population. Write necessary member functions for the following:
i. Accept details of n cities
ii. Display details of n cities in ascending order of population.
iii. Display details of a particular city.
(Use Array of object and to display city information use manipulators.)*/
#include <bits/stdc++.h>
using namespace std;

class City
{
public:
    int cityCode, population;
    string cityName;

    void setData()
    {
        cout << "Enter City Code: ";
        cin >> cityCode;
        cout << "Enter City Name: ";
        cin >> cityName;
        cout << "Enter Population: ";
        cin >> population;
    }

    void display()
    {
        cout << cityCode << " " << cityName << " " << population << endl;
    }

    void sort(City &c1, City &c2)
    {
        if (c1.population > c2.population)
        {
            City temp = c1;
            c1 = c2;
            c2 = temp;
        }
    }

    void displayCity(City &c1)
    {
        if (c1.cityName == cityName)
            cout << c1.cityName << " " << c1.population << endl;
        else
            cout << "City not found" << endl;
    }
};

int main()
{
    int n, choice;
    string cName;
    cout << "Enter number of cities: ";
    cin >> n;

    City *c;
    c = new City[n];

    do
    {
        cout << "Choose from the following options: " << endl;
        cout << "1. Accept Details of cities " << endl;
        cout << "2. Sort Cities in ascending order of population " << endl;
        cout << "3. Display details of a particular city " << endl;
        cout << "4. Exit " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                cout << "Enter Details for city " << i + 1 << " : " << endl;
                c[i].setData();
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    c[i].sort(c[i], c[j]);
                }
            }
            cout << "Details of cities in ascending order of population: " << endl;
            for (int i = 0; i < n; i++)
                c[i].display();
            break;

        case 3:
            cout << "Enter city name to find : ";
            cin >> cName;
            for (int i = 0; i < n; i++)
            {
                if (c[i].cityName == cName)
                    c[i].display();
                else
                    cout << "City not found" << endl;
            }
            break;

        case 4:
            cout << "Thank you" << endl;
            exit(1);
            break;
        }
    } while (choice != 4);

    return 0;
}