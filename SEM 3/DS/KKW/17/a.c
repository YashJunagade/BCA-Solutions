/*A) Write a ‘C’ program to read a postfix expression, evaluate it and display the result.
(Use Static Implementation of Stack).
*/

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>
// #define MAX 100

// char stack[MAX], postfix[MAX];
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
//         printf("stack is underflow");
//     else
//     {
//         data = stack[top];
//         top--;
//     }
//     return data;
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
//                 printf("Invalid Operator\n");
//             }
//         }
//     }
//     return pop();
// }

// int main()
// {
//     printf("Enter PostFix Expression: ");
//     gets(postfix);

//     int ans = evaluatePostfix(postfix);
//     printf("Result is %d", ans);
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char postfix[MAX], stack[MAX];
int i, top = -1;

void push(char data)
{
    if (top == MAX - 1)
        printf("Stack is overflow");
    else
    {
        top++;
        stack[top] = data;
    }
}

char pop()
{
    char data;
    if (top == -1)
        printf("stack is overflow");
    else
    {
        data = stack[top];
        top--;
    }
    return data;
}

int evalPost(char postfix[])
{
    int i, op1, op2, len = strlen(postfix);
    char c;
    for (i = 0; i < len; i++)
    {
        c = postfix[i];
        if (isdigit(c))
        {
            push(c - '0');
        }
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
                printf("Invalid Operator");
            }
        }
    }
    return pop();
}

int main()
{
    printf("Enter Postfix Expression :");
    gets(postfix);

    int ans = evalPost(postfix);
    printf("Result : %d", ans);
    return 0;
}