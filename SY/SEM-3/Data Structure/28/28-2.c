#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node *next;
};

struct Node *temp, *head1, *head2, *newNode, *ptr;

struct Node *create(struct Node *head, int data)
{
     newNode = (struct Node *)malloc(sizeof(struct Node));
     newNode->data = data;
     newNode->next = NULL;

     if (head == NULL)
          head = temp = newNode;
     else
     {
          temp->next = newNode;
          temp = newNode;
     }

     return head;
}

void display(struct Node *head)
{
     ptr = head;
     while (ptr != NULL)
     {
          printf("%d\t", ptr->data);
          ptr = ptr->next;
     }
}

int main()
{
     int num, choice;

     do
     {
          printf("Enter the number :");
          scanf("%d", &num);
          if (num >= 0)
               head1 = create(head1, num);
          else
               head2 = create(head2, num);

          printf("Do you want to add more Node(yes-1 & no-0) :");
          scanf("%d", &choice);
     } while (choice == 1);

     printf("Positive Linked List :\n");
     display(head1);
     printf("\nNegative Linked List :\n");
     display(head2);
}