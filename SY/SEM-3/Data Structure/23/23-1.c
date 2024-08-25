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
          printf("\t%d", ptr->data);
}

// Search for a value in the linked list
void search(int val)
{
     node *ptr;
     int pos;

     for (ptr = list, pos = 1; ptr != NULL && ptr->data != val; ptr = ptr->next, pos++)
          ;
     if (ptr != NULL && ptr->data == val)
          printf("Value is found in LL at position %d.", pos);
     else
          printf("Value not found.");
}

// Insert a new node at the end of the linked list
void insertend()
{
     node *temp;
     temp = getnode();
     last->next = temp;
     last = temp;
}

// Delete a node at a specific position
node *deletepos()
{
     int pos, i;
     node *ptr, *prev;
     printf("\nEnter the position for deleting node: ");
     scanf("%d", &pos);

     if (pos == 1)
     {
          ptr = list;
          list = ptr->next;
          free(ptr);
     }
     else
     {
          for (ptr = list, prev = list, i = 1; ptr != NULL && i < pos; prev = ptr, ptr = ptr->next, i++)
               ;
          if (ptr != NULL)
          {
               prev->next = ptr->next;
               free(ptr);
          }
          else
               printf("\nPosition not found.");
     }
     return list;
}

void main()
{
     int ch, val;
     clrscr();

     while (1)
     {
          printf("\n1: Create the Linked List.");
          printf("\n2: Display the Linked List.");
          printf("\n3: Insert at Last Position.");
          printf("\n4: Delete by Position");
          printf("\n5: Exit.");
          printf("\nEnter your choice: ");
          scanf("%d", &ch);
          switch (ch)
          {
          case 1:
               create();
               break;
          case 2:
               display();
               break;
          case 3:
               insertend();
               break;
          case 4:
               list = deletepos();
               break;
          case 5:
               exit(0);
               break;
          }
     }
     getch();
}
