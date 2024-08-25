#include <stdio.h>
#include <conio.h>
#include <malloc.h> // For malloc function

// Define a node in the circular doubly linked list
struct NODE
{
     int data;
     struct NODE *next;
     struct NODE *prev;
};

typedef struct NODE node;
node *head = NULL; // Head of the list

// Function to create a new node
node *getnode()
{
     node *temp;
     temp = (node *)malloc(sizeof(node));
     printf("\nEnter the data: ");
     scanf("%d", &temp->data);
     temp->next = NULL;
     temp->prev = NULL;
     return temp;
}

// Function to create a Circular Doubly Linked List
void create()
{
     int n, i;
     node *temp, *last;

     printf("\nEnter the number of nodes: ");
     scanf("%d", &n);

     if (n <= 0)
     {
          printf("\nInvalid number of nodes.");
          return;
     }

     // Create the first node
     head = getnode();
     last = head;

     // Create the remaining nodes
     for (i = 1; i < n; i++)
     {
          temp = getnode();
          last->next = temp;
          temp->prev = last;
          last = temp;
     }

     // Link the last node to the head to make it circular
     last->next = head;
     head->prev = last;
}

// Function to display the Circular Doubly Linked List
void display()
{
     node *ptr;

     if (head == NULL)
     {
          printf("\nThe list is empty.");
          return;
     }

     printf("\nThe Circular Doubly Linked List is:\n");
     ptr = head;

     // Traverse the list and print data
     do
     {
          printf("%d <-> ", ptr->data);
          ptr = ptr->next;
     } while (ptr != head);

     printf("(head)\n"); // Indicate that we have come back to the head
}

void main()
{
     clrscr(); // Clear the screen

     create();  // Create the Circular Doubly Linked List
     display(); // Display the Circular Doubly Linked List

     getch(); // Wait for a key press
}
