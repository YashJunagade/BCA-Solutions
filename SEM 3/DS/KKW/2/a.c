/*A) Write a ‘C’ program to accept a string from a user and reverse it using Static
implementation of Stack.
*/

// #include <stdio.h>
// #define MAX 100

// int top = -1, i;
// char stack[MAX], str[MAX];

// char pop()
// {
//     char temp;
//     if (top == -1)
//         printf("Stack is underflow ");
//     else
//     {
//         temp = stack[top];
//         top--;
//     }
//     return temp;
// }

// char push(char c)
// {
//     if (top == MAX - 1)
//         printf("Stack is overflow");
//     else
//     {
//         top++;
//         stack[top] = c;
//     }
// }

// int main()
// {
//     printf("Enter String :");
//     gets(str);

//     while (str[i] != '\0')
//     {
//         push(str[i]);
//         i++;
//     }

//     printf("String Reverse :\n");
//     while (top != -1)
//     {
//         printf("%c", pop());
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 100

// char stack[MAX], str[MAX];
// int top = -1, i;

// void push(char data)
// {
//     if (top == MAX - 1)
//         printf("Stack is overflow");
//     else
//     {
//         top++;
//         stack[top] = data;
//     }
// }

// char pop()
// {
//     char data;
//     if (top == -1)
//         printf("Stack is underflow");
//     else
//     {
//         data = stack[top];
//         top--;
//     }
//     return data;
// }

// void reverseStr(char *str)
// {
//     int len = strlen(str);
//     for (i = 0; i < len; i++)
//         push(str[i]);
//     while (top != -1)
//         printf("%c", pop());
// }

// int main()
// {
//     printf("Enter the string :");
//     gets(str);
//     printf("Reverse string :");
//     reverseStr(str);
// }

#include <stdio.h>
#include <string.h>
#define MAX 100

int top = -1;
char str[MAX], stack[MAX];

void push(char c)
{
    if (top == MAX - 1)
        printf("Stack is overflow");
    else
    {
        top++;
        stack[top] = c;
    }
}

char pop()
{
    char c;
    if (top == -1)
        printf("stack is empty");
    else
    {
        c = stack[top];
        top--;
    }
    return c;
}

void reverseStr(char str[])
{
    int i, len = strlen(str);
    for (i = 0; i < len; i++)
        push(str[i]);
    for (i = 0; i < len; i++)
        printf("%c", pop());
}

int main()
{
    printf("Enter the string :");
    gets(str);

    printf("Reverse string :");
    reverseStr(str);
}