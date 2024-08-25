#include <stdio.h>
#include <conio.h>

struct NODE
{
     int data;
     struct NODE *next;
};
typedef struct NODE node;

node *list = NULL, *last;

// Create a new node with user input
node *getnode()
{
     node *temp;
     temp = (node *)malloc(sizeof(node));
     printf("\nEnter the data: ");
     scanf("%d", &temp->data);
     temp->next = NULL;
     return temp;
}

// Create a linked list with 'n' nodes
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

// Display the entire linked list
void display()
{
     node *ptr;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
          printf("%d->", ptr->data);
     printf("NULL");
}

// Display alternate nodes in the linked list
void displayalternate()
{
     node *ptr;
     int cnt;
     for (ptr = list, cnt = 1; ptr != NULL; ptr = ptr->next, cnt++)
     {
          if (cnt % 2 != 0)
               printf("%d->", ptr->data);
     }
     printf("NULL");
}

void main()
{
     clrscr(); // Clear screen
     create();
     display();
     printf("\nAlternate nodes in LL: ");
     displayalternate();
     getch(); // Wait for user input
}
