#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Define the structure for a node in the singly linked list
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

// Function to insert a node at the end of the singly linked list
void insertEnd(struct Node **head, int data)
{
     struct Node *newNode = createNode(data);
     if (*head == NULL)
     {
          *head = newNode;
     }
     else
     {
          struct Node *temp = *head;
          while (temp->next != NULL)
          {
               temp = temp->next;
          }
          temp->next = newNode;
     }
}

// Function to display the singly linked list
void displayList(struct Node *head)
{
     if (head == NULL)
     {
          printf("List is empty.\n");
          return;
     }
     struct Node *temp = head;
     while (temp != NULL)
     {
          printf("%d ", temp->data);
          temp = temp->next;
     }
     printf("\n");
}

// Function to sort the singly linked list using Bubble Sort
void sortList(struct Node *head)
{
     if (head == NULL)
          return;

     int swapped;
     struct Node *ptr1;
     struct Node *lptr = NULL;

     // Bubble sort algorithm
     do
     {
          swapped = 0;
          ptr1 = head;

          while (ptr1->next != lptr)
          {
               if (ptr1->data > ptr1->next->data)
               {
                    // Swap data
                    int temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = 1;
               }
               ptr1 = ptr1->next;
          }
          lptr = ptr1;
     } while (swapped);
}

// Main function
void main()
{

     clrscr();

     struct Node *head = NULL; // Initialize head to NULL

     // Insert elements into the singly linked list
     insertEnd(&head, 30);
     insertEnd(&head, 10);
     insertEnd(&head, 20);
     insertEnd(&head, 50);
     insertEnd(&head, 40);

     printf("Original List: ");
     displayList(head);

     sortList(head); // Sort the list

     printf("Sorted List: ");
     displayList(head);

     getch();
}
