#include <stdio.h>
#include <conio.h>
#define MAX 50

struct STACK
{
     char stk[MAX];
     int top;
};
typedef struct STACK stack;

void initstack(stack *s)
{
     s->top = -1; // Initialize top to -1 (stack is empty)
}

int isempty(stack *s)
{
     return s->top == -1; // Return 1 if empty, else 0
}

int isfull(stack *s)
{
     return s->top == MAX - 1; // Return 1 if full, else 0
}

void push(stack *s, char data)
{
     s->stk[++s->top] = data; // Push data onto stack
}

char pop(stack *s)
{
     return s->stk[s->top--]; // Pop data from stack
}

void main()
{
     stack s;
     char string[MAX];
     int i;
     clrscr();

     initstack(&s); // Initialize the stack

     printf("\nEnter the String: ");
     gets(string); // Input string

     for (i = 0; string[i] != '\0'; i++)
     {
          if (isfull(&s))
               printf("\nStack is FULL.");
          else
               push(&s, string[i]); // Push each char to stack
     }

     printf("\nReverse String: ");
     while (!isempty(&s))
          printf("%c", pop(&s)); // Pop to reverse the string

     getch(); // Wait for key press
}
