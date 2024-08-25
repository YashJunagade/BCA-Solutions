#include <stdio.h>
#include <conio.h>

struct NODE
{
     int data;
     struct NODE *next;
};

typedef struct NODE node;

node *list = NULL, *last;

node *getnode() // Create a new node
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

void display() // Display the linked list
{
     node *ptr;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
          printf("\t%d", ptr->data); // Print each node's data
}

void search(int val) // Search for a value in the linked list
{
     node *ptr;
     int pos;
     for (ptr = list, pos = 1; ptr != NULL && ptr->data != val; ptr = ptr->next, pos++)
          ; // Traverse the list to find the value
     if (ptr != NULL && ptr->data == val)
          printf("Value is found in LL at %d position.", pos); // Value found
     else
          printf("Value not found."); // Value not found
}

void insertend() // Insert a new node at the end of the list
{
     node *temp;
     temp = getnode();  // Create a new node
     last->next = temp; // Link new node to the end of the list
     last = temp;       // Update last pointer
}

void main()
{
     int ch, val;
     clrscr();

     while (1)
     {
          printf("\n1: Create the Linked list.");
          printf("\n2: Display the Linked List.");
          printf("\n3: Search.");
          printf("\n4: Insert at Last Position.");
          printf("\n5: Exit.");
          printf("\nEnter the choice: ");
          scanf("%d", &ch);
          switch (ch)
          {
          case 1:
               create(); // Create the list
               break;
          case 2:
               display(); // Display the list
               break;
          case 3:
               printf("\nEnter the value to be searched: ");
               scanf("%d", &val);
               search(val); // Search for a value
               break;
          case 4:
               insertend(); // Insert at the end
               break;
          case 5:
               exit(); // Exit the program
          }
     }
     getch(); // Wait for key press
}
