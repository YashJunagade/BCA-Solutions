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

// Count non-zero, even, and odd numbers in the list
void count()
{
     int nonzero = 0, even = 0, odd = 0;
     node *ptr;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
     {
          if (ptr->data != 0)
               nonzero++;
          if (ptr->data % 2 == 0)
               even++;
          else
               odd++;
     }
     printf("\nTotal non-zero Numbers = %d", nonzero);
     printf("\nTotal even Numbers = %d", even);
     printf("\nTotal odd Numbers = %d", odd);
}

void main()
{
     int ch, val;
     clrscr();
     create();  // Create the linked list
     display(); // Display the linked list
     count();   // Count and display non-zero, even, and odd numbers
     getch();   // Wait for user input
}
