#include <stdio.h>
#include <conio.h>

struct NODE
{
     int data;
     struct NODE *next;
};
typedef struct NODE node;

node *list = NULL, *last;

// Create a new node with input data
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
          printf("%d->", ptr->data);
     printf("NULL");
}

// Remove the last node and add it at the beginning of the list
node *removelastaddfirst()
{
     node *ptr, *prev;

     // Traverse to the last node
     for (ptr = list, prev = list; ptr->next != NULL; prev = ptr, ptr = ptr->next)
          ;

     // Remove last node
     prev->next = NULL;

     // Add removed node at the beginning
     ptr->next = list;
     list = ptr;

     return list;
}

void main()
{
     int ch, val;
     clrscr();

     // Create and display the initial list
     create();
     display();

     // Remove last node and add it at the beginning
     list = removelastaddfirst();
     printf("\nList after removing last node and adding at first: ");
     display();

     getch();
}
