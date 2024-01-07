// /*B) Write a ‘C’ program to create doubly link list and display nodes having odd value*/

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
//         if (ptr->data % 2 == 1)
//             printf("%d\t", ptr->data);
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
//         newNode->prev = newNode->next = NULL;

//         if (head == NULL)
//             head = temp = newNode;
//         else
//         {
//             temp->next = newNode;
//             newNode->prev = temp;
//             temp = newNode;
//         }
//         printf("Do you want to add more Node (yes-1 & no-0) :");
//         scanf("%d", &choice);
//     } while (choice == 1);

//     printf("Doubly Linked List With Odd Value :\n");
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
        if (ptr->data % 2 != 0)
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
        newNode->next = newNode->prev = NULL;

        if (head == NULL)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
        printf("Do you want to add more nodes(yes-1 & no-0) :");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Doubly Linked List with Odd Value :\n");
    display(head);
}