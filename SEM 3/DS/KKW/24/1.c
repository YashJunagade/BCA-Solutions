/*A) Write a ‘C’ program to read a postfix expression, evaluate it and display the result.
(Use Dynamic Implementation of Stack)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top, *temp, *newNode;

void push(int data)
{
    newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->data = data;
    newNode->next = NULL;
    if (top == NULL)
        top = newNode;
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

int pop()
{
    int data;
    temp = top;
    if (top == NULL)
        printf("Stack is empty");
    else
    {
        data = top->data;
        top = top->next;
        free(temp);
    }
    return data;
}

int evalPost(char postfix[])
{
    int op1, op2, i, len = strlen(postfix);
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
                printf("Invalide Operator");
            }
        }
    }
    return pop();
}

int main()
{
    char postfix[30];
    printf("Enter Postfix Expression :");
    gets(postfix);
    int ans = evalPost(postfix);
    printf("Result : %d ", ans);
}