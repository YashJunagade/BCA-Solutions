#include <stdio.h>
#include <conio.h>

#define MAX 50

struct STACK
{
     char stk[MAX];
     int top;
};

typedef struct STACK stack;

// Initialize the stack
void initstack(stack *s)
{
     s->top = -1; // Stack is empty when top is -1
}

int isempty(stack *s)
{
     if (s->top == -1)
          return 1; // Stack is empty
     else
          return 0; // Stack is not empty
}

int isfull(stack *s)
{
     if (s->top == MAX - 1)
          return 1; // Stack is full
     else
          return 0; // Stack is not full
}

void push(stack *s, char data)
{
     s->top++;              // Move the top index up
     s->stk[s->top] = data; // Push the data onto the stack
}

char pop(stack *s)
{
     char val;
     val = s->stk[s->top]; // Get the top element
     s->top--;             // Move the top index down
     return val;           // Return the popped element
}

char gettop(stack *s)
{
     return s->stk[s->top]; // Return the top element without removing it
}

void display(stack *s)
{
     int i;
     // Display all elements in the stack
     for (i = 0; i <= s->top; i++)
          printf("%c", s->stk[i]);
}

int isoperator(char symbol)
{
     // Check if the symbol is an operator
     if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
          return 1; // It is an operator
     else
          return 0; // It is not an operator
}

int priority(char oper)
{
     // Determine the precedence of the operator
     if (oper == '^')
          return 4; // Highest precedence
     else if (oper == '/' || oper == '*')
          return 3; // Medium precedence
     else if (oper == '+' || oper == '-')
          return 2; // Lower precedence
     else
          return 1; // Default precedence
}

int checktop(char topsymb)
{
     // Check if the top symbol is a parenthesis
     if (topsymb == '(' || topsymb == '{' || topsymb == '[')
          return 1; // It is a parenthesis
     else
          return 0; // It is not a parenthesis
}

void inpostfix(char *E)
{
     int i, j = 0;
     char symbol, postfix[MAX], topsymb;
     stack s;
     initstack(&s);

     printf("Symbol postfix\tstack");
     for (i = 0; E[i] != '\0'; i++)
     {
          symbol = E[i];
          if (symbol == '(' || symbol == '{' || symbol == '[')
               push(&s, symbol); // Push opening parenthesis onto stack
          else if (isoperator(symbol) == 1)
          {
               // Pop operators from stack with higher or equal precedence
               while (!isempty(&s) && priority(gettop(&s)) >= priority(symbol))
                    postfix[j++] = pop(&s);
               push(&s, symbol); // Push the current operator onto stack
          }
          else if (symbol == ')' || symbol == '}' || symbol == ']')
          {
               // Pop operators until matching opening parenthesis
               topsymb = pop(&s);
               while (!checktop(topsymb))
               {
                    postfix[j++] = topsymb;
                    topsymb = pop(&s);
               }
          }
          else
               postfix[j++] = symbol; // Directly append operands
          postfix[j] = '\0';
          printf("\n%c %s\t\t", symbol, postfix);
          display(&s);
          getch();
     }
     while (!isempty(&s))
     {
          postfix[j++] = pop(&s); // Pop remaining operators from the stack
          postfix[j] = '\0';
          printf("\n%c %s\t\t", symbol, postfix);
          display(&s);
     }

     // Display the final postfix expression
     printf("\nPostfix Expression: %s", postfix);
}

main()
{
     char expr[MAX];
     clrscr(); // Clear the screen
     printf("\nEnter the Infix Expression: ");
     scanf(" %s", expr);
     inpostfix(expr); // Convert infix to postfix
     getch();         // Wait for key press
}
