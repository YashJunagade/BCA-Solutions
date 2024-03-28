/*Write a C++ program to create a class Movie with data members M_Name, Release_Year, Director_Name and Budget. (Use File Handling)
Write necessary member functions to:
i. Accept details for 'n' Movies from user and store it in a file "Movie.txt".
ii. Display Movie details from a file.
iii. Count the number of objects stored in a file.*/

#include <bits/stdc++.h>
using namespace std;

class Movie
{
public:
    string mName, dName;
    int rYear;
    long long budget;

    void setData()
    {
        cout << "Enter Movie Name: ";
        cin >> mName;
        cout << "Enter Movie Director Name: ";
        cin >> dName;
        cout << "Enter Movie Release Year: ";
        cin >> rYear;
        cout << "Enter Movie Budget: ";
        cin >> budget;
    }

    void writeToFile()
    {
        ofstream file("Movie.txt", ios::app);
        file << "Movie Name : " << mName << endl
             << "Director Name : " << dName << endl
             << "Release Year : " << rYear << endl
             << "Budget : " << budget << endl;

        file.close();
        cout << "Data written to file successfully!" << endl;
    }

    static void readFromFile()
    {
        ifstream file("Movie.txt");
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }

    static int countFromFile()
    {
        ifstream file("Movie.txt");
        int count = 0;
        string line;
        while (getline(file, line))
        {
            if (line.find("Movie Name") != string::npos)
                count++;
        }
        cout << "Number of objects : " << count << endl;
        file.close();
    }
};

int main()
{
    int n;
    cout << "Enter number of movies : ";
    cin >> n;

    Movie m;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for movie " << i + 1 << " : " << endl;
        m.setData();
        m.writeToFile();
    }

    cout << "Movies Details " << endl;
    Movie::readFromFile();
    Movie::countFromFile();

    return 0;
}