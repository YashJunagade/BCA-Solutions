#include <stdio.h>
#include <conio.h>

struct NODE
{
     int data;
     struct NODE *next;
};

typedef struct NODE node;

node *front = NULL, *rear = NULL;

int isempty() // Check if the queue is empty
{
     if (front == NULL && rear == NULL)
          return 1; // Queue is empty
     else
          return 0; // Queue is not empty
}

node *getnodenum(int data) // Create a new node with given data
{
     node *temp;
     temp = (node *)malloc(sizeof(node)); // Allocate memory for the node
     temp->data = data;                   // Set the data for the node
     temp->next = NULL;                   // Initialize next pointer to NULL
     return temp;                         // Return the new node
}

void add(int data) // Add a new node to the end of the queue
{
     node *temp;
     temp = getnodenum(data); // Create a new node
     if (front == NULL)       // If the queue is empty
     {
          rear = temp; // Set both front and rear to the new node
          front = temp;
     }
     else
     {
          rear->next = temp; // Link the new node to the end of the queue
          rear = temp;       // Update the rear to the new node
     }
}

int deleteq() // Remove and return the front node's data from the queue
{
     node *ptr;
     int val;
     ptr = front;              // Point to the front node
     val = front->data;        // Store the data of the front node
     if (front->next != NULL)  // If there are more nodes in the queue
          front = front->next; // Update front to the next node
     else
     {
          front = NULL; // Queue is empty now
          rear = NULL;  // Clear rear pointer
     }
     free(ptr);  // Free the memory of the removed node
     return val; // Return the data of the removed node
}

void display() // Display all the nodes in the queue
{
     node *ptr;
     for (ptr = front; ptr != rear; ptr = ptr->next)
          printf(" %d", ptr->data); // Print each node's data
     printf(" %d", ptr->data);      // Print the last node's data
}

void main()
{
     int ch, data;
     clrscr(); // Clear the screen

     while (1)
     {
          printf("\n1: Add.");
          printf("\n2: Delete");
          printf("\n3: Display.");
          printf("\n4: Exit");

          printf("\nEnter the Choice: ");
          scanf("%d", &ch); // Input the user's choice
          switch (ch)
          {
          case 1:
               printf("\nEnter the data to insert in queue: ");
               scanf("%d", &data);
               add(data); // Add data to the queue
               break;
          case 2:
               if (isempty())
                    printf("\nQueue is Empty!");
               else
                    printf("\nDeleted element is: %d", deleteq()); // Delete and show the front element
               break;
          case 3:
               if (isempty())
                    printf("\nQueue is Empty!");
               else
                    display(); // Display the queue
               break;
          case 4:
               exit(1); // Exit the program
          }
     }
     getch(); // Wait for key press
}
