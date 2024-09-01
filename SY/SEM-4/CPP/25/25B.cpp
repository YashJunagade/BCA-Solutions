/*Write a C++ program to read the contents of a "SampleData.txt" file. Create "Upper.txt" file to store uppercase characters, "Lower.txt" file
to store lowercase characters, "Digit.txt" file to store digits and "Other.txt" file to store remaining characters of a given file.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream in("SampleData.txt");
    ofstream ufile("Upper.txt");
    ofstream lfile("Lower.txt");
    ofstream dfile("Digit.txt");
    ofstream ofile("Other.txt");

    char ch;
    while (in.get(ch))
    {
        if (isupper(ch))
            ufile << ch;
        else if (islower(ch))
            lfile << ch;
        else if (isdigit(ch))
            dfile << ch;
        else
            ofile << ch;
    }

    cout << "Data is sorted into files";
    return 0;
}