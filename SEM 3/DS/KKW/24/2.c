/*B) Write a ‘C’ program to remove last node of the singly linked list and insert it at the
beginning of list.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode, *temp, *head, *ptr;

int deleteLastNode(struct Node *head)
{
    struct Node *temp;
    int data;
    ptr = head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;

    temp = ptr->next;
    data = temp->data;
    free(temp);
    ptr->next = NULL;
    return data;
}

struct Node *insertAtBeg(struct Node *head, int data)
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = head;
    head = newNode;

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
    int data, choice;
    do
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data :");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        printf("Do you want to add more nodes(yes-1 & no-0) :");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Original Linked List :\n");
    display(head);

    int ans = deleteLastNode(head);
    head = insertAtBeg(head, ans);
    printf("\nAfter removing last element and insert at beginning :\n");
    display(head);
    return 0;
}