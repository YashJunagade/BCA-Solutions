#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack data structure
typedef struct
{
     int top;
     char items[MAX];
} Stack;

void push(Stack *s, char item)
{
     if (s->top < MAX - 1)
     {
          s->items[++(s->top)] = item;
     }
}

char pop(Stack *s)
{
     if (s->top >= 0)
     {
          return s->items[(s->top)--];
     }
     return '\0';
}

char peek(Stack *s)
{
     if (s->top >= 0)
     {
          return s->items[s->top];
     }
     return '\0';
}

int isEmpty(Stack *s)
{
     return s->top == -1;
}

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

void infixToPrefix(char *infix, char *prefix)
{
     Stack s;
     s.top = -1;
     int length = strlen(infix);
     int i, k = 0;

     // Reverse infix expression
     char rev_infix[MAX];
     for (i = length - 1; i >= 0; i--)
     {
          rev_infix[length - 1 - i] = infix[i];
     }
     rev_infix[length] = '\0';

     // Convert reversed infix to postfix
     char postfix[MAX];
     for (i = 0; rev_infix[i] != '\0'; i++)
     {
          if (isalnum(rev_infix[i]))
          {
               postfix[k++] = rev_infix[i];
          }
          else if (rev_infix[i] == '(')
          {
               push(&s, ')');
          }
          else if (rev_infix[i] == ')')
          {
               while (!isEmpty(&s) && peek(&s) != ')')
               {
                    postfix[k++] = pop(&s);
               }
               pop(&s);
          }
          else
          {
               while (!isEmpty(&s) && precedence(rev_infix[i]) <= precedence(peek(&s)))
               {
                    postfix[k++] = pop(&s);
               }
               push(&s, rev_infix[i]);
          }
     }
     while (!isEmpty(&s))
     {
          postfix[k++] = pop(&s);
     }
     postfix[k] = '\0';

     // Reverse postfix to get prefix
     for (i = strlen(postfix) - 1; i >= 0; i--)
     {
          prefix[strlen(postfix) - 1 - i] = postfix[i];
     }
     prefix[strlen(postfix)] = '\0';
}

int main()
{
     char infix[MAX], prefix[MAX];

     clrscr(); // Clear the screen (Turbo C specific)

     printf("Enter infix expression: ");
     gets(infix); // Read the infix expression

     infixToPrefix(infix, prefix);

     printf("Prefix expression: %s\n", prefix);

     getch(); // Wait for user input before closing (Turbo C specific)
     return 0;
}
