#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define MAX 100

// Structure for stack
typedef struct
{
     char *data;
     int top;
     int capacity;
} Stack;

// Function to create a stack
Stack *createStack(int capacity)
{
     Stack *stack = (Stack *)malloc(sizeof(Stack));
     stack->capacity = capacity;
     stack->top = -1;
     stack->data = (char *)malloc(stack->capacity * sizeof(char));
     return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
     return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack)
{
     return stack->top == stack->capacity - 1;
}

// Function to push an element to the stack
void push(Stack *stack, char item)
{
     if (isFull(stack))
     {
          printf("Stack overflow\n");
          return;
     }
     stack->data[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(Stack *stack)
{
     if (isEmpty(stack))
     {
          printf("Stack underflow\n");
          return '\0';
     }
     return stack->data[stack->top--];
}

// Function to get the top element of the stack without popping
char peek(Stack *stack)
{
     if (!isEmpty(stack))
     {
          return stack->data[stack->top];
     }
     return '\0';
}

// Function to check the precedence of operators
int precedence(char op)
{
     switch (op)
     {
     case '+':
     case '-':
          return 1;
     case '*':
     case '/':
          return 2;
     case '^':
          return 3;
     default:
          return 0;
     }
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix, char *postfix)
{
     Stack *stack = createStack(MAX);
     int i = 0, k = 0;

     while (infix[i] != '\0')
     {
          if (isalnum(infix[i]))
          {
               postfix[k++] = infix[i];
          }
          else if (infix[i] == '(')
          {
               push(stack, infix[i]);
          }
          else if (infix[i] == ')')
          {
               while (!isEmpty(stack) && peek(stack) != '(')
               {
                    postfix[k++] = pop(stack);
               }
               pop(stack); // Remove '(' from stack
          }
          else
          { // Operator
               while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i]))
               {
                    postfix[k++] = pop(stack);
               }
               push(stack, infix[i]);
          }
          i++;
     }

     // Pop all remaining operators from the stack
     while (!isEmpty(stack))
     {
          postfix[k++] = pop(stack);
     }
     postfix[k] = '\0'; // Null terminate the postfix expression
     free(stack->data);
     free(stack);
}

// Main function
void main()
{
     char infix[MAX], postfix[MAX];

     clrscr(); // Clear the screen

     printf("Enter the infix expression: ");
     gets(infix); // Read the infix expression

     infixToPostfix(infix, postfix);

     printf("Postfix expression: %s\n", postfix);

     getch(); // Wait for a key press
}
