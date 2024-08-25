#include <stdio.h>
#include <conio.h>
#include <string.h> // Include for strcmp function
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
     s->top = -1;
}

// Check if the stack is empty
int isempty(stack *s)
{
     return (s->top == -1);
}

// Check if the stack is full
int isfull(stack *s)
{
     return (s->top == MAX - 1);
}

// Push an element onto the stack
void push(stack *s, char data)
{
     s->stk[++s->top] = data;
}

// Pop an element from the stack
char pop(stack *s)
{
     return s->stk[s->top--];
}

void main()
{
     stack s;
     char string[50], revstr[50];
     int i, j = 0;

     clrscr(); // Clear screen
     initstack(&s);
     printf("\nEnter the String: ");
     gets(string); // Read the string

     // Push each character onto the stack
     for (i = 0; string[i] != '\0'; i++)
     {
          if (isfull(&s))
               printf("\nStack is FULL.");
          else
               push(&s, string[i]);
     }

     // Pop each character to form the reversed string
     while (!isempty(&s))
          revstr[j++] = pop(&s);
     revstr[j] = '\0'; // Null-terminate the reversed string

     // Check if the original and reversed strings are the same
     if (strcmp(string, revstr) == 0)
          printf("\nString is Palindrome.");
     else
          printf("\nString is not Palindrome.");

     getch(); // Wait for user input
}
