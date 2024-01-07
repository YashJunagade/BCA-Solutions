// /*A) Write a C program to accept an infix expression and convert it into postfix
// form.(Use Static Implementation of Stack)
// Example: - A * B + C as AB*C+
// */

// #include <stdio.h>
// #include <string.h>
// #define MAX 100

// char infix[MAX], postfix[MAX], stack[MAX];
// int top = -1;

// void push(char c)
// {
//     if (top == MAX - 1)
//         printf("Stack overflow");
//     else
//     {
//         top++;
//         stack[top] = c;
//     }
// }
// char pop()
// {
//     int temp;
//     if (top == -1)
//         printf("Stack underflow");
//     else
//     {
//         temp = stack[top];
//         top--;
//     }
//     return temp;
// }

// int isSpace(char c)
// {
//     if (c == '\t' || c == ' ')
//         return 1;
//     else
//         return 0;
// }

// int isEmpty()
// {
//     if (top == -1)
//         return 1;
//     else
//         return 0;
// }

// int precedence(char c)
// {
//     switch (c)
//     {
//     case '^':
//         return 3;
//         break;
//     case '*':
//     case '/':
//         return 2;
//     case '+':
//     case '-':
//         return 1;
//         break;
//     default:
//         return 0;
//     }
// }

// void inToPostfix()
// {
//     int i, j = 0;
//     char symbol, temp;

//     for (i = 0; i < strlen(infix); i++)
//     {
//         symbol = infix[i];
//         if (!isSpace(symbol))
//         {
//             switch (symbol)
//             {
//             case '(':
//                 push(symbol);
//                 break;
//             case ')':
//                 while ((temp = pop()) != '(')
//                 {
//                     postfix[j] = temp;
//                     j++;
//                 }
//                 break;
//             case '^':
//             case '*':
//             case '/':
//             case '+':
//             case '-':
//                 while ((!isEmpty()) && precedence(symbol) <= precedence(top))
//                 {
//                     postfix[j] = pop();
//                     j++;
//                 }
//                 push(symbol);
//                 break;
//             default:
//                 postfix[j] = symbol;
//                 j++;
//                 break;
//             }
//         }
//     }
//     while (!isEmpty())
//     {
//         postfix[j] = pop();
//         j++;
//     }
//     postfix[j] = '\0';
// }

// void display()
// {
//     int i;
//     for (i = 0; i < strlen(postfix); i++)
//         printf("%c ", postfix[i]);
// }

// int main()
// {
//     printf("Enter the Infix Expression :");
//     gets(infix);

//     inToPostfix();
//     printf("Postfix Expression :");
//     display();

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 100

// char postfix[MAX], infix[MAX], stack[MAX];
// int top = -1, i;

// void inToPost()
// {
//     int j = 0, len = strlen(postfix);
//     char symbol, temp;

//     for (i = 0; i < len; i++)
//     {
//         symbol = postfix[i];
//         switch (symbol)
//         {
//         case '(':
//             push(symbol);
//             break;
//         case ')':
//             while ((temp = pop()) != ')')
//             {
//                 postfix[j] = temp;
//                 j++;
//             }
//             break;
//         case '+':
//         case '-':
//         case '*':
//         case '/':
//         case '^':
//             while ((!isdigit()) && precedence(stack[top]) >= precedence(symbol))
//             {
//                 postfix[j] = pop();
//                 j++;
//             }
//             push(symbol);
//             break;
//         default:
//             postfix[j] = symbol;
//             j++;
//         }
//     }
//     while ((!isEmpty()))
//     {
//         postfix[j] = pop();
//         j++;
//     }
//     postfix[j] = '\0';
// }

// int main()
// {
//     printf("Enter Infix Expression :");
//     gets(infix);

//     inToPost();

//     printf("Postfix Expression :\n");
//     display(postfix);
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define MAX 100

// char infix[MAX], postfix[MAX], stack[MAX];
// int top = -1;

// void push(char data)
// {
//     if (top == MAX - 1)
//     {
//         printf("Stack is overflow");
//     }
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
//     }
//     else
//     {
//         data = stack[top];
//         top--;
//     }
//     return data;
// }

// int precedence(char c)
// {
//     switch (c)
//     {
//     case '^':
//         return 3;
//     case '*':
//     case '/':
//         return 2;
//     case '+':
//     case '-':
//         return 1;
//     default:
//         return 0;
//     }
// }

// int isSpace(char c)
// {
//     if (c == ' ' || c == '\t')
//         return 1;
//     else
//         return 0;
// }

// int isEmpty()
// {
//     if (top == -1)
//         return 1;
//     else
//         return 0;
// }

// void inToPost()
// {
//     int i, j, len = strlen(infix);
//     char symbol, temp;

//     for (i = 0, j = 0; i < len; i++)
//     {
//         symbol = infix[i];
//         if (!isSpace(symbol))
//         {
//             switch (symbol)
//             {
//             case '(':
//                 push(symbol);
//                 break;
//             case ')':
//                 while ((temp = pop()) != '(')
//                 {
//                     postfix[j] = temp;
//                     j++;
//                 }
//                 break;
//             case '^':
//             case '/':
//             case '*':
//             case '+':
//             case '-':
//                 while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
//                 {
//                     postfix[j] = pop();
//                     j++;
//                 }
//                 push(symbol);
//                 break;
//             default:
//                 postfix[j] = symbol;
//                 j++;
//             }
//         }
//     }
//     while (!isEmpty())
//     {
//         postfix[j] = pop();
//         j++;
//     }
//     postfix[j] = '\0';
// }

// void display(char postfix[])
// {
//     int i;
//     for (i = 0; postfix[i] != '\0'; i++)
//     {
//         printf("%c ", postfix[i]);
//     }
// }

// int main()
// {
//     printf("Enter Infix Expression: ");
//     gets(infix);

//     inToPost();

//     printf("Postfix Expression: ");
//     display(postfix);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char infix[MAX], postfix[MAX], stack[MAX];
int top = -1, i;

int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isSpace(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

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
        printf("Stack is underflow");
    else
    {
        c = stack[top];
        top--;
    }
    return c;
}

void inToPost(char infix[])
{
    int i, j = 0, len = strlen(infix);
    char c, temp;
    for (i = 0; i < len; i++)
    {
        c = infix[i];
        if (!isSpace(c))
        {
            switch (c)
            {
            case '(':
                push(c);
                break;
            case ')':
                while ((temp = pop()) != '(')
                {
                    postfix[j++] = temp;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while ((!isEmpty()) && precedence(stack[top]) >= precedence(c))
                {
                    postfix[j++] = pop();
                }
                push(c);
                break;
            default:
                postfix[j++] = c;
            }
        }
    }
    while ((!isEmpty()))
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void display(char postfix[])
{
    for (i = 0; i < postfix[i] != '\0'; i++)
        printf("%c", postfix[i]);
}

int main()
{
    printf("Enter the Infix Expression :");
    gets(infix);

    inToPost(infix);
    printf("Postfix Expression :");
    display(postfix);
    return 0;
}