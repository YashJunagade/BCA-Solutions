/*Create a C++ class MyFile with data members file pointer and filename. Write necessary member
functions to accept and display File. Overload the following operators:
Operator example        purpose
1. +   f3 = f1 + f2     Concatenate the contents of file F1 and F2 in F3.
2. !    !f3             Changes the case of alternate characters of file F3.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Max 10

class myFile
{
    FILE *fp;
    char fn[Max];

public:
    myFile(const char *fname)
    {
        strncpy(fn, fname, Max - 1);
        fn[Max - 1] = '\0';
    }

    myFile operator+(myFile &f2)
    {
        myFile ans("sy.txt");
        char ch;
        fp = fopen(fn, "r");
        f2.fp = fopen(f2.fn, "r"); // Corrected line
        ans.fp = fopen(ans.fn, "w");
        while ((ch = fgetc(fp)) != EOF)
        {
            fputc(ch, ans.fp);
        }
        fclose(fp);

        while ((ch = fgetc(f2.fp)) != EOF)
        {
            fputc(ch, ans.fp);
        }
        fclose(f2.fp);

        fclose(ans.fp);
        return ans;
    }

    void operator!()
    {
        myFile ans("sy.txt");
        char ch;
        fp = fopen(fn, "r");
        ans.fp = fopen(ans.fn, "w");
        int count = 0;
        while ((ch = fgetc(fp)) != EOF)
        {
            if (count % 2 == 0)
            {
                if (isupper(ch))
                    fputc(tolower(ch), ans.fp);
                else if (islower(ch))
                    fputc(toupper(ch), ans.fp);
                else
                    fputc(ch, ans.fp);
            }
            else
            {
                fputc(ch, ans.fp);
            }
            count++;
        }

        fclose(fp);
        fclose(ans.fp);
    }

    void display()
    {
        fp = fopen(fn, "r");
        char ch;
        while ((ch = fgetc(fp)) != EOF)
            cout << ch;
        fclose(fp);
    }
};

int main()
{
    myFile f1("f1.txt");
    myFile f2("f2.txt");
    myFile f3("f3.txt");
    cout << "First file:\n";
    f1.display();
    cout << "\nSecond file:\n";
    f2.display();
    f3 = f1 + f2;
    cout << "\nAfter concatenation, file is:\n";
    f3.display();
    cout << "\nAfter changing case:\n";
    !f3;
    f3.display();
    return 0;
}
