#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct NODE
{
     int data;
     struct NODE *next;
};
typedef struct NODE node;

node *list = NULL, *last = NULL;

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

// Create a linked list with user-specified number of nodes
void create()
{
     int n, i;
     node *temp;

     printf("\nEnter the number of nodes to be created: ");
     scanf("%d", &n);
     for (i = 0; i < n; i++)
     {
          temp = getnode();
          if (list == NULL)
          {
               list = temp;
               last = temp;
          }
          else
          {
               last->next = temp;
               last = temp;
          }
     }
}

// Display the linked list
void display()
{
     node *ptr;
     if (list == NULL)
     {
          printf("\nThe list is empty.");
          return;
     }
     printf("\nLinked List: ");
     for (ptr = list; ptr != NULL; ptr = ptr->next)
     {
          printf("%d -> ", ptr->data);
     }
     printf("NULL");
}

// Main menu-driven function
void main()
{
     int choice;

     clrscr(); // Clear the screen

     while (1)
     {
          printf("\n\nMenu:");
          printf("\n1. Create Linked List");
          printf("\n2. Display Linked List");
          printf("\n3. Exit");
          printf("\nEnter your choice: ");
          scanf("%d", &choice);

          switch (choice)
          {
          case 1:
               create();
               break;
          case 2:
               display();
               break;
          case 3:
               exit(0);
          default:
               printf("\nInvalid choice. Please try again.");
          }
     }

     getch(); // Wait for a key press
}
