/*B) Write a ‘C’ program to swap mth and nth element of singly linked list.
 */

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *temp, *head, *newNode, *ptr;

// struct Node *swapNodes(struct Node *head, int mdata, int ndata)
// {
//     struct Node *m, *n;
//     ptr = head;
//     while (ptr != NULL)
//     {
//         if (ptr->data == mdata)
//             m = ptr;
//         if (ptr->data == ndata)
//             n = ptr;
//         ptr = ptr->next;
//     }

//     int temp = m->data;
//     m->data = n->data;
//     n->data = temp;
//     return head;
// }

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
//     int data, choice, m, n;
//     do
//     {
//         newNode = (struct Node *)malloc(sizeof(struct Node));
//         printf("Enter the data :");
//         scanf("%d", &data);
//         newNode->data = data;
//         newNode->next = NULL;

//         if (head == NULL)
//             head = temp = newNode;
//         else
//         {
//             temp->next = newNode;
//             temp = newNode;
//         }
//         printf("Do you want to add more nodes(yes-1 & no-0) :");
//         scanf("%d", &choice);
//     } while (choice == 1);

//     printf("Enter the mth and nth position : ");
//     scanf("%d %d", &m, &n);

//     printf("Original Linked List :\n");
//     display(head);

//     printf("\nLinked List After swapping :\n");
//     head = swapNodes(head, m, n);
//     display(head);
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *temp, *head, *newNode, *ptr;

struct Node *swap(struct Node *head, int mdata, int ndata)
{
    struct Node *m, *n;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == mdata)
            m = ptr;
        if (ptr->data == ndata)
            n = ptr;
        ptr = ptr->next;
    }

    int temp = n->data;
    n->data = m->data;
    m->data = temp;

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
    int data, choice, m, n;

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

    printf("Enter the mth and nth element: ");
    scanf("%d %d", &m, &n);

    printf("Original Linked List :\n");
    display(head);

    head = swap(head, m, n);
    printf("\nSwap Linked List :\n");
    display(head);
}