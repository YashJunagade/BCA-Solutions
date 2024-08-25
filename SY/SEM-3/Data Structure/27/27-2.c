#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
     int data;
     struct Node *next;
     struct Node *prev;
} Node;

// Function to create a new node
Node *createNode(int data)
{
     Node *newNode = (Node *)malloc(sizeof(Node));
     newNode->data = data;
     newNode->next = NULL;
     newNode->prev = NULL;
     return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(Node **head, int data)
{
     Node *newNode = createNode(data);
     if (*head == NULL)
     {
          *head = newNode;
     }
     else
     {
          Node *temp = *head;
          while (temp->next != NULL)
          {
               temp = temp->next;
          }
          temp->next = newNode;
          newNode->prev = temp;
     }
}

// Function to display the doubly linked list
void displayList(Node *head)
{
     Node *temp = head;
     printf("Doubly Linked List: ");
     while (temp != NULL)
     {
          printf("%d ", temp->data);
          temp = temp->next;
     }
     printf("\n");
}

int main()
{
     Node *head = NULL;
     int n, i, data;

     clrscr(); // Clear the screen (Turbo C specific)

     printf("Enter number of elements: ");
     scanf("%d", &n);
     printf("Enter %d elements:\n", n);
     for (i = 0; i < n; i++)
     {
          scanf("%d", &data);
          insertEnd(&head, data);
     }

     displayList(head);

     // Free allocated memory (optional for demonstration)
     Node *temp;
     while (head != NULL)
     {
          temp = head;
          head = head->next;
          free(temp);
     }

     getch(); // Wait for user input before closing (Turbo C specific)
     return 0;
}
