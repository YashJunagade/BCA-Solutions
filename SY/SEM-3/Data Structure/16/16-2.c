#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
struct NODE
{
     int data;
     struct NODE *next;
};
typedef struct NODE node;

node *head = NULL; // Head of the list

// Function to create a new node
node *getnode()
{
     node *temp = (node *)malloc(sizeof(node));
     printf("Enter the data for the node: ");
     scanf("%d", &temp->data);
     temp->next = NULL;
     return temp;
}

// Function to create the linked list
void create()
{
     int n, i;
     node *temp, *last;

     printf("Enter the number of nodes to be created: ");
     scanf("%d", &n);

     for (i = 0; i < n; i++)
     {
          temp = getnode();
          if (head == NULL)
          {
               head = temp;
          }
          else
          {
               last->next = temp;
          }
          last = temp;
     }
}

// Function to display the linked list
void display()
{
     node *ptr = head;
     if (ptr == NULL)
     {
          printf("The list is empty.\n");
          return;
     }

     printf("Linked List: ");
     while (ptr != NULL)
     {
          printf("%d -> ", ptr->data);
          ptr = ptr->next;
     }
     printf("NULL\n");
}

// Function to search for a number in the linked list
void search(int value)
{
     node *ptr = head;
     int pos = 1;

     while (ptr != NULL)
     {
          if (ptr->data == value)
          {
               printf("Number %d found at position %d.\n", value, pos);
               return;
          }
          ptr = ptr->next;
          pos++;
     }
     printf("Number not found.\n");
}

// Main function to drive the program
void main()
{
     int num;

     clrscr(); // Clear the screen

     create();  // Create the linked list
     display(); // Display the linked list

     printf("Enter the number to search: ");
     scanf("%d", &num);

     search(num); // Search for the number in the list

     getch(); // Wait for a key press
}
