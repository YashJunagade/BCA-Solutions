#include <stdio.h>
#include <conio.h>

struct NODE
{
     int data;
     struct NODE *next;
};
typedef struct NODE node;

node *list = NULL, *last;

// Create a new node
node *getnode()
{
     node *temp;
     temp = (node *)malloc(sizeof(node));
     printf("\nEnter the data: ");
     scanf("%d", &temp->data);
     temp->next = NULL;
     return temp;
}

// Create a linked list with n nodes
void create()
{
     int n, i;
     node *temp;

     printf("\nEnter total nodes to be created: ");
     scanf("%d", &n);
     for (i = 0; i < n; i++)
     {
          temp = getnode();
          if (list == NULL)
               list = temp;
          else
               last->next = temp;
          last = temp;
     }
}

// Display the linked list
void display()
{
     node *ptr;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
          printf("\t%d", ptr->data);
}

// Swap data between two nodes at specified positions
void swap()
{
     node *ptr, *ptr1;
     int pos, m, n, temp;
     printf("\nEnter the position of mth and nth to be swapped: ");
     scanf("%d%d", &m, &n);

     // Locate the mth node
     for (ptr = list, pos = 1; ptr != NULL && pos < m; ptr = ptr->next, pos++)
          ;
     // Locate the nth node
     for (ptr1 = list, pos = 1; ptr1 != NULL && pos < n; ptr1 = ptr1->next, pos++)
          ;

     if (ptr != NULL && ptr1 != NULL)
     {
          // Swap data between mth and nth nodes
          temp = ptr->data;
          ptr->data = ptr1->data;
          ptr1->data = temp;
     }
     else
          printf("\nPosition is invalid");
}

void main()
{
     clrscr();  // Clear screen
     create();  // Create the linked list
     display(); // Display the original list
     swap();    // Swap nodes
     printf("\nLinked list after Swapping: ");
     display(); // Display the list after swapping
     getch();   // Wait for user input
}
