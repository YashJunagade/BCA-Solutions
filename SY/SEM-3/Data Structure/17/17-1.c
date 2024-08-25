#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50 // Maximum size of the stack

// Define the structure for the stack
typedef struct
{
     int top;
     int arr[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack *s)
{
     s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s)
{
     return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s)
{
     return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int value)
{
     if (isFull(s))
     {
          printf("Stack overflow\n");
          return;
     }
     s->arr[++(s->top)] = value;
}

// Function to pop an element from the stack
int pop(Stack *s)
{
     if (isEmpty(s))
     {
          printf("Stack underflow\n");
          exit(1);
     }
     return s->arr[(s->top)--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char *expr)
{
     Stack s;
     initStack(&s);
     char *p = expr;

     while (*p)
     {
          if (isdigit(*p))
          {
               push(&s, *p - '0'); // Convert char digit to int
          }
          else
          {
               int op2 = pop(&s);
               int op1 = pop(&s);
               switch (*p)
               {
               case '+':
                    push(&s, op1 + op2);
                    break;
               case '-':
                    push(&s, op1 - op2);
                    break;
               case '*':
                    push(&s, op1 * op2);
                    break;
               case '/':
                    if (op2 != 0)
                         push(&s, op1 / op2);
                    else
                    {
                         printf("Division by zero\n");
                         exit(1);
                    }
                    break;
               default:
                    printf("Invalid operator\n");
                    exit(1);
               }
          }
          p++;
     }
     return pop(&s);
}

// Main function to drive the program
void main()
{
     char expr[MAX];
     int result;

     clrscr(); // Clear the screen

     printf("Enter the postfix expression (e.g., 23*54*+): ");
     gets(expr); // Read postfix expression from user

     result = evaluatePostfix(expr);

     printf("The result of the postfix expression is: %d\n", result);

     getch(); // Wait for a key press
}
