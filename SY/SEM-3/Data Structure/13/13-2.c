#include <stdio.h>
#include <conio.h>

struct NODE
{
     struct NODE *prev; // Pointer to the previous node
     int data;          // Data of the node
     struct NODE *next; // Pointer to the next node
};

typedef struct NODE node;

node *list = NULL, *last; // Pointers for the start and end of the list

node *getnode()
{
     node *temp;
     temp = (node *)malloc(sizeof(node)); // Allocate memory for a new node
     printf("\nEnter the data: ");
     scanf("%d", &temp->data); // Read data for the node
     temp->prev = NULL;        // Initialize previous pointer
     temp->next = NULL;        // Initialize next pointer
     return temp;
}

void create()
{
     int n, i;
     node *temp;
     printf("\nEnter total nodes: ");
     scanf("%d", &n); // Read the number of nodes to create

     for (i = 0; i < n; i++)
     {
          temp = getnode(); // Get a new node
          if (list == NULL)
               list = temp; // Set the first node
          else
          {
               last->next = temp; // Link previous last node to new node
               temp->prev = last; // Set the previous pointer of new node
          }
          last = temp; // Update the last node to the new node
     }
}

void display()
{
     node *ptr;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
          printf("%d->", ptr->data); // Print data of each node
     printf("->NULL");               // End of the list
}

void displayodd()
{
     node *ptr;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
     {
          if ((ptr->data % 2) != 0)
               printf("%d->", ptr->data); // Print odd data
     }
     printf("->NULL"); // End of the list
}

void main()
{
     clrscr(); // Clear the screen
     create(); // Create the doubly linked list
     printf("\nDoubly LL: ");
     display(); // Display the entire list
     printf("\nOdd values in Doubly LL: ");
     displayodd(); // Display only the odd values
     getch();      // Wait for user input
}
