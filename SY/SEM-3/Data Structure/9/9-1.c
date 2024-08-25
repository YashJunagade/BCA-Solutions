#include <stdio.h>
#include <conio.h>
#include <math.h> // Required for pow function

#define MAX 30

struct STACK
{
     double stk[MAX]; // Array to hold stack elements
     int top;         // Index of the top element
};
typedef struct STACK stack;

// Initialize the stack
void initstack(stack *s)
{
     int i;
     for (i = 0; i < MAX; i++)
          s->stk[i] = 0; // Set all elements to 0
     s->top = -1;        // Set top to -1 indicating an empty stack
}

// Check if the stack is empty
int isempty(stack *s)
{
     return s->top == -1; // Return 1 if stack is empty
}

// Check if the stack is full
int isfull(stack *s)
{
     return s->top == MAX - 1; // Return 1 if stack is full
}

// Push data onto the stack
void push(stack *s, double data)
{
     if (!isfull(s))
     {
          s->stk[++s->top] = data; // Increment top and add data
     }
}

// Pop data from the stack
double pop(stack *s)
{
     if (!isempty(s))
     {
          return s->stk[s->top--]; // Return top element and decrement top
     }
     return 0; // Return 0 if stack is empty (error handling)
}

// Display stack elements
void display(stack *s)
{
     int i;
     printf("\nStack: ");
     for (i = 0; i <= s->top; i++)
          printf("\t%f", s->stk[i]); // Print each element
}

// Check if a character is a digit
int isdigit(char symb)
{
     return symb >= '0' && symb <= '9'; // Return 1 if character is a digit
}

// Evaluate an expression with two operands and an operator
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
          return pow(opnd1, opnd2); // Use pow for exponentiation
     default:
          return 0; // Default case for unknown operators
     }
}

// Check if a character is an operator
int isoperator(char symbol)
{
     return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^';
}

// Convert expression from variables to digits
char *convert(char *expr)
{
     int i, j, scnt = 0, symval[10], flag = 0;
     char symbol[10];

     // Initialize first symbol
     symbol[scnt++] = expr[0];
     printf("\nEnter the Value of %c: ", expr[0]);
     scanf("%d", &symval[0]);
     expr[0] = symval[0] + 48; // Convert to ASCII character

     for (i = 1; expr[i] != '\0'; i++)
     {
          flag = 0;
          if (!isoperator(expr[i]))
          { // Process non-operator characters
               for (j = 0; j < scnt; j++)
               {
                    if (expr[i] == symbol[j])
                    {
                         flag = 1;
                         expr[i] = symval[j] + 48; // Convert to ASCII character
                         break;
                    }
               }
               if (!flag)
               { // New symbol
                    symbol[scnt] = expr[i];
                    printf("\nEnter the Value of %c: ", expr[i]);
                    scanf("%d", &symval[scnt]);
                    expr[i] = symval[scnt] + 48; // Convert to ASCII character
                    scnt++;
               }
          }
     }
     printf("\n Expression after converting into digit form=%s", expr);
     return expr;
}

// Evaluate postfix expression
double posteval(char *expr)
{
     stack s;
     int i;
     double opnd1, opnd2, result;

     initstack(&s);
     expr = convert(expr); // Convert variables to digits

     for (i = 0; expr[i] != '\0'; i++)
     {
          if (isdigit(expr[i]))
          {
               push(&s, expr[i] - 48); // Push digit onto stack
          }
          else
          {
               opnd2 = pop(&s);                      // Pop second operand
               opnd1 = pop(&s);                      // Pop first operand
               result = eval(opnd1, opnd2, expr[i]); // Evaluate
               push(&s, result);                     // Push result back onto stack
          }
     }
     return pop(&s); // Return final result
}

void main()
{
     char expr[MAX];
     clrscr(); // Clear screen
     printf("\nEnter the Expression: ");
     scanf(" %s", expr);                                             // Read postfix expression
     printf("\nResult after postfix Evaluation=%f", posteval(expr)); // Print result
     getch();                                                        // Wait for user input
}
