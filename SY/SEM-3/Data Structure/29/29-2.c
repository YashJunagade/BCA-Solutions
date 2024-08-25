#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Define the structure for a node in the circular singly linked list
struct Node
{
     int data;
     struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
     newNode->data = data;
     newNode->next = NULL;
     return newNode;
}

// Function to insert a node at the end of the circular singly linked list
void insertEnd(struct Node **head, int data)
{
     struct Node *newNode = createNode(data);
     if (*head == NULL)
     {
          // If the list is empty, make the new node the head and point it to itself
          *head = newNode;
          newNode->next = *head;
     }
     else
     {
          struct Node *temp = *head;
          // Traverse to the last node
          while (temp->next != *head)
          {
               temp = temp->next;
          }
          // Insert the new node and update pointers
          temp->next = newNode;
          newNode->next = *head;
     }
}

// Function to display the circular singly linked list
void displayList(struct Node *head)
{
     if (head == NULL)
     {
          printf("List is empty.\n");
          return;
     }
     struct Node *temp = head;
     // Traverse the list and print data
     do
     {
          printf("%d ", temp->data);
          temp = temp->next;
     } while (temp != head);
     printf("\n");
}

// Main function
int main()
{
     struct Node *head = NULL; // Initialize head to NULL

     clrscr(); // Clear the screen

     // Inserting nodes into the circular singly linked list
     insertEnd(&head, 10);
     insertEnd(&head, 20);
     insertEnd(&head, 30);
     insertEnd(&head, 40);

     // Displaying the circular singly linked list
     printf("Circular Singly Linked List: ");
     displayList(head);

     getch(); // Wait for a key press to close the console window
     return 0;
}
