/*B) Write a ‘C’ program to evaluate a given polynomial using function. (Use array).*/

// #include <stdio.h>
// #include <math.h>

// int polynomial(int c[], int degree, int x)
// {
//     int i, result = 0;
//     for (i = 0; i <= degree; i++)
//         result += c[i] * pow(x, i);
//     return result;
// }

// int main()
// {
//     int x, degree, c[10], i, ans;
//     printf("Enter the degree of polynomial :");
//     scanf("%d", &degree);
//     for (i = 0; i <= degree; i++)
//     {
//         printf("Enter the coefficient for X^%d :", i);
//         scanf("%d", &c[i]);
//     }
//     printf("Enter the value of X :");
//     scanf("%d", &x);

//     ans = polynomial(c, degree, x);
//     printf("The answer is %d", ans);
// }

// #include <stdio.h>
// #include <math.h>

// int polynomial(int c[], int degree, int x)
// {
//     int i, result = 0;
//     for (i = 0; i <= degree; i++)
//         result += c[i] * pow(x, i);
//     return result;
// }

// int main()
// {
//     int degree, c[10], x, i;
//     printf("Enter the degree of polynomial :");
//     scanf("%d", &degree);
//     for (i = 0; i <= degree; i++)
//     {
//         printf("Enter the coefficient for X^%d :", i);
//         scanf("%d", &c[i]);
//     }
//     printf("Enter the value of X :");
//     scanf("%d", &x);

//     int ans = polynomial(c, degree, x);
//     printf("the answer is %d ", ans);

//     return 0;
// }

#include <stdio.h>
#include <math.h>

int evalPoly(int c[], int degree, int x)
{
    int result = 0, i;
    for (i = 0; i <= degree; i++)
    {
        result += c[i] * pow(x, i);
    }
    return result;
}

int main()
{
    int degree, c[10], x, i;
    printf("Enter the degree of polynomial :");
    scanf("%d", &degree);

    for (i = 0; i <= degree; i++)
    {
        printf("Enter the coefficient for X^%d :", i);
        scanf("%d", &c[i]);
    }
    printf("Enter the value of X :");
    scanf("%d", &x);

    int result = evalPoly(c, degree, x);
    printf("The answer is: %d", result);
    return 0;
}