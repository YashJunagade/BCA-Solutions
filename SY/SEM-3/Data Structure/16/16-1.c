#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // Required for malloc and free

struct NODE
{
     char data;         // Data of the node (character)
     struct NODE *next; // Pointer to the next node
};

typedef struct NODE node;

node *top = NULL; // Top of the stack

// Function to create a new node with given data
node *getnodenum(char data)
{
     node *temp;
     temp = (node *)malloc(sizeof(node)); // Allocate memory for the new node
     temp->data = data;                   // Set the data for the new node
     temp->next = NULL;                   // Initialize the next pointer to NULL
     return temp;                         // Return the newly created node
}

// Function to check if the stack is empty
int isempty()
{
     return (top == NULL); // Return 1 if top is NULL (stack is empty), otherwise return 0
}

// Function to push a new character onto the stack
void push(char data)
{
     node *temp;
     temp = getnodenum(data); // Create a new node with the given data
     temp->next = top;        // Point the new node's next to the current top
     top = temp;              // Update the top to the new node
}

// Function to pop a character from the stack
char pop()
{
     char val;
     node *ptr;
     ptr = top;       // Get the node at the top of the stack
     val = ptr->data; // Retrieve the data from the top node
     top = ptr->next; // Update the top to the next node
     free(ptr);       // Free the memory of the old top node
     return val;      // Return the data of the popped node
}

void main()
{
     int i;
     char string[50];
     clrscr(); // Clear the screen
     printf("\nEnter the String: ");
     gets(string); // Read a string from user (Note: gets is unsafe, consider using fgets)

     // Push each character of the string onto the stack
     for (i = 0; string[i] != '\0'; i++)
          push(string[i]);

     printf("\nReverse String:");

     // Pop each character from the stack to reverse the string
     while (!isempty())
          printf("%c", pop());

     getch(); // Wait for user input
}
