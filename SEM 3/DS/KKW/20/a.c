/*A) Write a ‘C’ program which accept the string and check whether the string is
Palindrome or not using stack. (Use Static/Dynamic implementation of Stack)
*/

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define MAX 100
// char str[MAX], stack[MAX];
// int i, top = -1;

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

// int isEmpty()
// {
//     if (top == -1)
//         return 1;
//     else
//         return 0;
// }

// void isPalindrome(char *str)
// {
//     int len = strlen(str);

//     for (i = 0; i < len; i++)
//         push(str[i]);

//     i = 0;
//     while (str[i])
//     {
//         if (isEmpty() || str[i] != pop())
//         {
//             printf("String is not palindrome");
//             exit(1);
//         }
//         i++;
//     }
//     printf("String is palindrome");
// }

// int main()
// {
//     printf("Enter a string :");
//     scanf("%s", str);

//     isPalindrome(str);
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define MAX 100

// char stack[MAX], str[MAX];
// int i, top = -1;

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
//     {
//         printf("Stack is underflow");
//         exit(1);
//     }

//     data = stack[top];
//     top--;
//     return data;
// }

// int isEmpty()
// {
//     if (top == -1)
//         return 1;
//     else
//         return 0;
// }

// void isPalindrome(char *str)
// {
//     int len = strlen(str);
//     for (i = 0; i < len; i++)
//         push(str[i]);

//     i = 0;
//     while (str[i])
//     {
//         if (isEmpty() || str[i] != pop())
//         {
//             printf("String is not palindrome");
//             exit(1);
//         }
//         i++;
//     }
//     printf("String is palindrome");
// }

// int main()
// {
//     printf("Enter a string :");
//     scanf("%s", str);

//     isPalindrome(str);
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define MAX 100

// char stack[MAX], str[MAX];
// int top = -1, i;

// void push(char data)
// {
//     if (top == MAX - 1)
//         printf("stack is overflow");
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
//     {
//         printf("Stack is underflow");
//         exit(1);
//     }
//     data = stack[top];
//     top--;
//     return data;
// }

// int isEmpty()
// {
//     if (top == -1)
//         return 1;
//     else
//         return 0;
// }

// void isPalindrome(char *str)
// {
//     int len = strlen(str);
//     for (i = 0; i < len; i++)
//         push(str[i]);
//     i = 0;
//     while (str[i])
//     {
//         if (isEmpty() || str[i] != pop())
//         {
//             printf("String is not a Palindrome ");
//             exit(1);
//         }
//         i++;
//     }
//     printf("String is Palindrome");
// }

// int main()
// {
//     printf("Enter string :");
//     scanf("%s", str);

//     isPalindrome(str);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char str[MAX], stack[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
        printf("Stack Overflow");
    else
    {
        top++;
        stack[top] = c;
    }
}

char pop()
{
    char temp;
    if (top == -1)
        printf("Stack underflow");
    else
    {
        temp = stack[top];
        top--;
    }
    return temp;
}

void isPalindrome(char str[])
{
    int i, len = strlen(str), mid = len / 2;
    for (i = 0; i < len; i++)
        push(str[i]);
    i = 0;
    while (str[i])
    {
        if (pop() != str[i])
        {
            printf("is not palindrome");
            exit(1);
        }
        i++;
    }
    printf("Is palindrome");
}

int main()
{
    printf("Enter The String :");
    gets(str);

    isPalindrome(str);
    return 0;
}