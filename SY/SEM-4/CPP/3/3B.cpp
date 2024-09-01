/*Write a C++ program to accept 'n' numbers from user through Command Line Argument.
Store all Even and Odd numbers in file "Even.txt" and "Odd.txt" respectively.*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ofstream evenFile("Even.txt");
    ofstream oddFile("Odd.txt");

    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <number1> <number2> ... <numberN>" << endl;
        return 1;
    }
    for (int i = 0; i < argc; i++)
    {
        int num = atoi(argv[i]);
        if (num % 2 == 0)
            evenFile << num << endl;
        else
            oddFile << num << endl;
    }

    evenFile.close();
    oddFile.close();
    return 0;
}