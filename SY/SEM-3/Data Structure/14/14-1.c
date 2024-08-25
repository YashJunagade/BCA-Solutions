#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Stack node structure
struct Node
{
     char data;
     struct Node *next;
};

// Stack structure
struct Stack
{
     struct Node *top;
};

// Function to initialize the stack
void initStack(struct Stack *stack)
{
     stack->top = NULL;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char data)
{
     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
     newNode->data = data;
     newNode->next = stack->top;
     stack->top = newNode;
}

// Function to pop an element from the stack
char pop(struct Stack *stack)
{
     if (stack->top == NULL)
     {
          printf("Stack underflow\n");
          return '\0'; // Return null character if stack is empty
     }
     struct Node *temp = stack->top;
     char data = temp->data;
     stack->top = stack->top->next;
     free(temp);
     return data;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
     return stack->top == NULL;
}

// Function to reverse the string using stack
void reverseString(char *str)
{
     struct Stack stack;
     initStack(&stack);

     // Push all characters of the string onto the stack
     for (int i = 0; str[i] != '\0'; i++)
     {
          push(&stack, str[i]);
     }

     // Pop all characters from the stack and place them back into the string
     int i = 0;
     while (!isEmpty(&stack))
     {
          str[i++] = pop(&stack);
     }
     str[i] = '\0'; // Null-terminate the reversed string
}

// Main function
void main()
{
     char str[100];

     clrscr(); // Clear the screen

     printf("Enter a string: ");
     gets(str); // Read the string from the user

     reverseString(str);

     printf("Reversed string: %s\n", str);

     getch(); // Wait for a key press
}
