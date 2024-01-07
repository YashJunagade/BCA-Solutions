// /*A) Write a program to accept a postfix expression and evaluate the expression using the stack.
// Example: Input: ab+cd-*
// Values: a=4, b=2, c=5, d=3
// Answer: 12
// */

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #define MAX 100

// char postfix[MAX];
// int top = -1, i;

// int pop()
// {
//     int temp;
//     if (top == -1)

//         printf("stack is underflow");
//     else
//     {
//         temp = postfix[top];
//         top--;
//     }
//     return temp;
// }

// void push(int n)
// {
//     if (top == MAX - 1)
//         printf("Stack is overflow");
//     else
//     {
//         top++;
//         postfix[top] = n;
//     }
// }

// int evaluatePostfix(char postfix[])
// {
//     for (i = 0; postfix[i] != '\0'; i++)
//     {
//         if (isdigit(postfix[i]))
//         {
//             push(postfix[i] - '0');
//         }
//         else
//         {
//             int op2 = pop();
//             int op1 = pop();

//             switch (postfix[i])
//             {
//             case '+':
//                 push(op1 + op2);
//                 break;
//             case '-':
//                 push(op1 - op2);
//                 break;
//             case '*':
//                 push(op1 * op2);
//                 break;
//             case '/':
//                 push(op1 / op2);
//                 break;
//             default:
//                 printf("Invalid operator ");
//                 exit(1);
//             }
//         }
//     }
//     return pop();
// }

// int main()
// {
//     printf("Enter Postfix Expression :");
//     gets(postfix);

//     int ans = evaluatePostfix(postfix);
//     printf("Result is %d", ans);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char postfix[MAX], stack[MAX];
int top = -1;

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
        printf("stack is underflow");
    else
    {
        c = stack[top];
        top--;
    }
    return c;
}

int evalPostfix(char postfix[])
{
    int i, op1, op2, len = strlen(postfix);
    char c;
    for (i = 0; i < len; i++)
    {
        c = postfix[i];
        if (isdigit(c))
            push(c - '0');
        else
        {
            op2 = pop();
            op1 = pop();
            switch (c)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            default:
                printf("Invalid operator");
            }
        }
    }
    return pop();
}

int main()
{
    printf("Enter Postfix Expression :");
    gets(postfix);

    int ans = evalPostfix(postfix);
    printf("Result : %d", ans);
    return 0;
}