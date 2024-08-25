#include <stdio.h>
#include <conio.h>

struct NODE
{
     int data;
     struct NODE *next;
};

typedef struct NODE node;

node *list = NULL, *last;

// Create a node with given data
node *getnodenum(int digit)
{
     node *temp;
     temp = (node *)malloc(sizeof(node)); // Allocate memory
     temp->data = digit;                  // Set node data
     temp->next = NULL;                   // Initialize next to NULL
     return temp;
}

// Create linked list from digits of the number
void createnumll(int num)
{
     int rem;
     node *temp;
     while (num > 0)
     {
          rem = num % 10;         // Get last digit
          num = num / 10;         // Remove last digit
          temp = getnodenum(rem); // Create new node
          if (list == NULL)
               list = temp; // Set first node
          else
          {
               temp->next = list; // Insert at beginning
               list = temp;       // Update head
          }
     }
}

// Display the linked list
void display()
{
     node *ptr;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
          printf("%d->", ptr->data); // Print node data
     printf("NULL");                 // End of list
}

void main()
{
     int num;
     clrscr(); // Clear screen
     printf("\nEnter the No: ");
     scanf("%d", &num); // Read number
     createnumll(num);  // Create list from number
     printf("\nLinked after separating the digits of num: ");
     display(); // Display linked list
     getch();   // Wait for user input
}
