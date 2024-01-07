/*B) Write a ‘C’ program to create a Circularly Doubly Linked list and display it.
 */

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next, *prev;
// };

// void display(struct Node *head)
// {
//     struct Node *ptr = head;
//     while (ptr != NULL)
//     {
//         printf("%d ", ptr->data);
//         ptr = ptr->next;
//         if (ptr == head)
//             break;
//     }
// }

// int main()
// {
//     struct Node *temp, *head, *newNode;
//     temp = head = newNode = NULL;
//     int choice, data;

//     do
//     {
//         newNode = (struct Node *)malloc(sizeof(struct Node));
//         printf("Enter the data :");
//         scanf("%d", &data);
//         newNode->data = data;
//         newNode->next = newNode->prev = NULL;

//         if (head == NULL)
//         {
//             head = temp = newNode;
//             temp->next = head;
//             head->prev = head;
//         }
//         else
//         {
//             temp->next = newNode;
//             newNode->prev = temp;
//             newNode->next = head;
//             head->prev = newNode;
//             temp = newNode;
//         }
//         printf("Do you want to add more node (yes-1 & no-0) :");
//         scanf("%d", &choice);
//     } while (choice == 1);

//     printf("Cicular Doubly Linked List :\n");
//     display(head);
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *prev, *next;
// };

// struct Node *temp, *head, *newNode, *ptr;

// void display(struct Node *head)
// {
//     ptr = head;
//     while (ptr != NULL)
//     {
//         printf("%d\t", ptr->data);
//         ptr = ptr->next;
//     }
// }

// int main()
// {
//     int data, choice;
//     do
//     {
//         newNode = (struct Node *)malloc(sizeof(struct Node));
//         printf("Enter the data :");
//         scanf("%d", &data);
//         newNode->data = data;
//         newNode->next = newNode->prev = NULL;

//         if (head == NULL)
//         {
//             head = temp = newNode;
//             newNode->next = head;
//             newNode->prev = head;
//         }
//         else
//         {
//             temp->next = newNode;
//             newNode->prev = temp;
//             head->prev = newNode;
//             temp = newNode;
//         }
//         printf("Do you want to add more node (yes-1 & no-0):");
//         scanf("%d", &choice);
//     } while (choice == 1);
//     printf("Cicular doubly linked list :\n");
//     display(head);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *temp, *head, *newNode, *ptr;

void display(struct Node *head)
{
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
        if (ptr == head)
            break;
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
        newNode->prev = newNode->next = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
            newNode->next = head;
            head->prev = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            head->prev = newNode;
            newNode->next = head;
            temp = newNode;
        }
        printf("Do you want to add more node (yes-1 & no-0):");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Circular Doubly Linked List :\n");
    display(head);
    return 0;
}