#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // Required for malloc and free

struct NODE
{
     int data;          // Data of the node (integer)
     struct NODE *next; // Pointer to the next node
};

typedef struct NODE node;

node *top = NULL; // Top of the stack

// Function to create a new node with given data
node *getnodenum(int data)
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

// Function to push a new integer onto the stack
void push(int data)
{
     node *temp;
     temp = getnodenum(data); // Create a new node with the given data
     temp->next = top;        // Point the new node's next to the current top
     top = temp;              // Update the top to the new node
}

// Function to pop an integer from the stack
int pop()
{
     int val;
     node *ptr;
     ptr = top;       // Get the node at the top of the stack
     val = ptr->data; // Retrieve the data from the top node
     top = ptr->next; // Update the top to the next node
     free(ptr);       // Free the memory of the old top node
     return val;      // Return the data of the popped node
}

// Function to display all elements in the stack
void display()
{
     node *ptr;
     for (ptr = top; ptr != NULL; ptr = ptr->next) // Traverse the stack
          printf("\t%d", ptr->data);               // Print each element
}

// Main function to interact with the stack
void main()
{
     int ch, data;
     clrscr(); // Clear the screen (Note: clrscr is specific to some compilers)

     while (1) // Infinite loop to continuously show menu
     {
          printf("\n1:PUSH.");
          printf("\n2:POP.");
          printf("\n3:Display.");
          printf("\n4:Exit.");
          printf("\nEnter the Choice:");
          scanf("%d", &ch);

          switch (ch)
          {
          case 1: // PUSH operation
               printf("\nEnter the data:");
               scanf("%d", &data);
               push(data); // Call push function to add data to the stack
               break;

          case 2: // POP operation
               if (isempty())
                    printf("\nStack is empty."); // Check if stack is empty before popping
               else
                    printf("\nPopped data from stack: %d", pop()); // Call pop function to remove and print data
               break;

          case 3: // Display operation
               if (isempty())
                    printf("\nStack is Empty."); // Check if stack is empty before displaying
               else
                    display(); // Call display function to print stack elements
               break;

          case 4:       // Exit operation
               exit(0); // Exit the program
          }
     }

     getch(); // Wait for user input (Note: getch is specific to some compilers)
}
