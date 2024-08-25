#include <stdio.h>
#include <conio.h>

struct NODE
{
     int data;
     struct NODE *next;
};

typedef struct NODE node;

node *list = NULL, *last;

node *getnode() // Create a node
{
     node *temp;
     temp = (node *)malloc(sizeof(node)); // Allocate memory for a new node
     printf("\nEnter the data: ");
     scanf("%d", &temp->data); // Input data for the node
     temp->next = NULL;        // Initialize next pointer to NULL
     return temp;              // Return the new node
}

void create()
{
     int n, i;
     node *temp;

     printf("\nEnter total nodes to be created: ");
     scanf("%d", &n); // Input number of nodes
     for (i = 0; i < n; i++)
     {
          temp = getnode(); // Create a new node
          if (list == NULL) // If list is empty, set the first node
               list = temp;
          else
               last->next = temp; // Link new node to the end of the list
          last = temp;            // Update last pointer
     }
}

void display(node *list)
{
     node *ptr;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
          printf("%d->", ptr->data); // Print each node's data
     printf("NULL");                 // End of the list
}

node *reverse() // Reverse the linked list
{
     node *ptr, *prev, *revlist = NULL;

     while (list != NULL)
     {
          for (ptr = list, prev = list; ptr->next != NULL; prev = ptr, ptr = ptr->next)
               ;                           // Traverse to the last node in the list
          if (ptr == list && prev == list) // If only one node exists
               list = NULL;
          prev->next = NULL; // Break the link
          if (revlist == NULL)
               revlist = ptr; // Initialize reversed list with last node
          else
               last->next = ptr; // Add node to the reversed list
          last = ptr;            // Update last pointer
     }
     return revlist; // Return the head of the reversed list
}

void main()
{
     int ch, val;
     node *revlist;

     clrscr();

     create();            // Create the list
     display(list);       // Display the original list
     revlist = reverse(); // Reverse the list
     printf("\nList after reversing: ");
     display(revlist); // Display the reversed list

     printf("\nOriginal list: ");
     display(list); // Display the original list (should be empty)

     getch(); // Wait for key press
}
