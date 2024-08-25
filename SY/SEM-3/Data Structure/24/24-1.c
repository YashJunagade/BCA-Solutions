#include <stdio.h>
#include <conio.h>
#include <math.h> // Required for pow function

#define MAX 30

struct STACK
{
     double stk[MAX];
     int top;
};
typedef struct STACK stack;

// Initialize the stack
void initstack(stack *s)
{
     for (int i = 0; i < MAX; i++)
          s->stk[i] = 0;
     s->top = -1;
}

// Check if the stack is empty
int isempty(stack *s)
{
     return s->top == -1;
}

// Check if the stack is full
int isfull(stack *s)
{
     return s->top == MAX - 1;
}

// Push a value onto the stack
void push(stack *s, double data)
{
     s->stk[++s->top] = data;
}

// Pop a value from the stack
double pop(stack *s)
{
     return s->stk[s->top--];
}

// Display the stack contents
void display(stack *s)
{
     printf("\nStack: ");
     for (int i = 0; i <= s->top; i++)
          printf("\t%f", s->stk[i]);
}

// Check if a character is a digit
int isdigit(char symb)
{
     return symb >= '0' && symb <= '9';
}

// Perform arithmetic operations
double eval(double opnd1, double opnd2, char symb)
{
     switch (symb)
     {
     case '+':
          return opnd1 + opnd2;
     case '-':
          return opnd1 - opnd2;
     case '*':
          return opnd1 * opnd2;
     case '/':
          return opnd1 / opnd2;
     case '^':
          return pow(opnd1, opnd2);
     }
     return 0;
}

// Evaluate postfix expression
double posteval(char *expr)
{
     stack s;
     initstack(&s);

     for (int i = 0; expr[i] != '\0'; i++)
     {
          if (isdigit(expr[i]))
               push(&s, expr[i] - 48);
          else
          {
               double opnd2 = pop(&s);
               double opnd1 = pop(&s);
               push(&s, eval(opnd1, opnd2, expr[i]));
          }
     }

     display(&s);
     return pop(&s);
}

void main()
{
     char expr[MAX];
     clrscr(); // Clear screen (specific to some compilers)
     printf("\nEnter the Expression: ");
     scanf(" %s", expr);

     printf("Result after postfix Evaluation = %f", posteval(expr));
     getch(); // Wait for user input (specific to some compilers)
}
