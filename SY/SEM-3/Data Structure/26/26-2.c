#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
     int data;
     struct Node *next;
} Node;

Node *createNode(int data)
{
     Node *newNode = (Node *)malloc(sizeof(Node));
     newNode->data = data;
     newNode->next = NULL;
     return newNode;
}

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
     }
}

void displayList(Node *head)
{
     Node *temp = head;
     while (temp != NULL)
     {
          printf("%d -> ", temp->data);
          temp = temp->next;
     }
     printf("NULL\n");
}

void concatenateLists(Node **head1, Node *head2)
{
     if (*head1 == NULL)
     {
          *head1 = head2;
     }
     else
     {
          Node *temp = *head1;
          while (temp->next != NULL)
          {
               temp = temp->next;
          }
          temp->next = head2;
     }
}

int main()
{
     Node *list1 = NULL, *list2 = NULL;
     int n, i, data;

     clrscr(); // Clear the screen (Turbo C specific)

     // Create first list
     printf("Enter number of elements for the first list: ");
     scanf("%d", &n);
     printf("Enter %d elements:\n", n);
     for (i = 0; i < n; i++)
     {
          scanf("%d", &data);
          insertEnd(&list1, data);
     }

     // Create second list
     printf("Enter number of elements for the second list: ");
     scanf("%d", &n);
     printf("Enter %d elements:\n", n);
     for (i = 0; i < n; i++)
     {
          scanf("%d", &data);
          insertEnd(&list2, data);
     }

     printf("First list: ");
     displayList(list1);

     printf("Second list: ");
     displayList(list2);

     concatenateLists(&list1, list2);

     printf("Concatenated list: ");
     displayList(list1);

     getch(); // Wait for user input before closing (Turbo C specific)
     return 0;
}
