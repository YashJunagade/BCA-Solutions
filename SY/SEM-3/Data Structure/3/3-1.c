#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // Include for malloc

struct NODE
{
     int data;
     struct NODE *next;
};

typedef struct NODE node;

// Function to create a new node and input data
node *getnode()
{
     node *temp;
     temp = (node *)malloc(sizeof(node)); // Allocate memory for the new node
     printf("\nEnter the data: ");
     scanf("%d", &temp->data);
     temp->next = NULL; // Initialize next pointer to NULL
     return temp;
}

// Function to create a linked list by appending nodes
node *create(node *list)
{
     node *temp, *last;
     int n, i;
     printf("\nEnter total nodes: ");
     scanf("%d", &n);
     for (i = 0; i < n; i++)
     {
          temp = getnode();
          if (list == NULL)
          {
               list = temp; // First node becomes the list head
          }
          else
          {
               // Traverse to the end and append the new node
               for (last = list; last->next != NULL; last = last->next)
                    ;
               last->next = temp;
          }
     }
     return list;
}

// Function to display the linked list
void display(node *list)
{
     node *ptr;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
     {
          printf("%d->", ptr->data);
     }
     printf("NULL");
}

// Function to create a new node with given data
node *getnodenum(int digit)
{
     node *temp;
     temp = (node *)malloc(sizeof(node));
     temp->data = digit;
     temp->next = NULL; // Initialize next pointer to NULL
     return temp;
}

// Function to search for a node with a specific value
node *search(int val, node *list1)
{
     node *ptr;
     for (ptr = list1; ptr != NULL && ptr->data != val; ptr = ptr->next)
          ;
     return ptr; // Returns NULL if not found
}

// Function to create the union of two linked lists
node *unionlist(node *list1, node *list2)
{
     node *lunion = NULL, *ptr1, *last, *temp, *ptr2, *ptr;

     // Add all nodes from list1 to lunion
     for (ptr1 = list1; ptr1 != NULL; ptr1 = ptr1->next)
     {
          temp = getnodenum(ptr1->data);
          if (lunion == NULL)
          {
               lunion = temp; // First node in union list
          }
          else
          {
               for (last = lunion; last->next != NULL; last = last->next)
                    ;
               last->next = temp; // Append node to the end of lunion
          }
     }

     // Add nodes from list2 only if they aren't in list1
     for (ptr2 = list2; ptr2 != NULL; ptr2 = ptr2->next)
     {
          ptr = search(ptr2->data, list1);
          if (ptr == NULL)
          { // If not found in list1
               temp = getnodenum(ptr2->data);
               for (last = lunion; last->next != NULL; last = last->next)
                    ;
               last->next = temp; // Append node to the end of lunion
          }
     }

     return (lunion); // Return the union of list1 and list2
}

void main()
{
     node *list1 = NULL, *list2 = NULL, *lunion;

     clrscr();

     printf("\nCreate list1: ");
     list1 = create(list1);

     printf("\nCreate List2: ");
     list2 = create(list2);

     printf("\nList1 is: ");
     display(list1);

     printf("\nList2 is : ");
     display(list2);

     lunion = unionlist(list1, list2); // Create union of list1 and list2

     printf("\nList after Union: ");
     display(lunion);

     getch();
}
