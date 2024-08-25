#include <stdio.h>
#include <conio.h> // For Turbo C's clrscr() and getch()

#define MAX 100 // Maximum size of the stack

// Stack structure
typedef struct
{
     int top;
     char items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack *s)
{
     s->top = -1;
}

// Function to push an element onto the stack
void push(Stack *s, char item)
{
     if (s->top == MAX - 1)
     {
          printf("Stack overflow\n");
     }
     else
     {
          s->items[++(s->top)] = item;
     }
}

// Function to pop an element from the stack
char pop(Stack *s)
{
     if (s->top == -1)
     {
          return '\0'; // Return a null character if stack is empty
     }
     else
     {
          return s->items[(s->top)--];
     }
}

// Function to check if the stack is empty
int isEmpty(Stack *s)
{
     return s->top == -1;
}

// Function to check if the given expression is parenthesized correctly
int isParenthesized(char *expr)
{
     Stack s;
     initStack(&s);

     char ch;
     while ((ch = *expr++) != '\0')
     {
          if (ch == '(' || ch == '{' || ch == '[')
          {
               push(&s, ch);
          }
          else if (ch == ')' || ch == '}' || ch == ']')
          {
               if (isEmpty(&s))
               {
                    return 0; // Stack is empty, but closing parenthesis found
               }
               char open = pop(&s);
               if ((ch == ')' && open != '(') ||
                   (ch == '}' && open != '{') ||
                   (ch == ']' && open != '['))
               {
                    return 0; // Mismatched parentheses
               }
          }
     }

     return isEmpty(&s); // If stack is empty, all parentheses are matched
}

int main()
{
     char expr[MAX];

     clrscr(); // Clear the screen (Turbo C specific)

     // Read the expression from the user
     printf("Enter the expression: ");
     gets(expr); // Use gets() to read the entire line of input

     // Check if the expression is parenthesized correctly
     if (isParenthesized(expr))
     {
          printf("The expression is correctly parenthesized.\n");
     }
     else
     {
          printf("The expression is not correctly parenthesized.\n");
     }

     getch(); // Wait for user input before closing (Turbo C specific)
     return 0;
}
