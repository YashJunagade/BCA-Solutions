#include <stdio.h>
#include <conio.h>

struct NODE
{
     int data;          // Node data
     struct NODE *next; // Pointer to next node
};

typedef struct NODE node;
node *list = NULL, *last; // Initialize list and last pointers

// Create a new node
node *getnode()
{
     node *temp;
     temp = (node *)malloc(sizeof(node)); // Allocate memory
     printf("\nEnter the data: ");
     scanf("%d", &temp->data); // Read node data
     temp->next = NULL;        // Initialize next pointer
     return temp;
}

// Create linked list with n nodes
void create()
{
     int n, i;
     node *temp;
     printf("\nEnter total nodes to be created: ");
     scanf("%d", &n); // Read number of nodes

     for (i = 0; i < n; i++)
     {
          temp = getnode(); // Get new node
          if (list == NULL)
               list = temp; // Set as first node
          else
               last->next = temp; // Append to last node
          last = temp;            // Update last node
     }
}

// Display all nodes in the list
void display()
{
     node *ptr;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
          printf("\t%d", ptr->data); // Print node data
}

// Count the number of nodes in the list
void count()
{
     node *ptr;
     int cnt;
     for (ptr = list, cnt = 0; ptr != NULL; ptr = ptr->next, cnt++)
          ;
     printf("\nTotal no of Nodes = %d", cnt); // Print total count
}

void main()
{
     clrscr();  // Clear screen
     create();  // Create linked list
     display(); // Display list
     count();   // Display node count
     getch();   // Wait for user input
}
