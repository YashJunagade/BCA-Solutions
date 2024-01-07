// /*B) Write a ‘C’ program to create a singly linked list, reverse it and display both the
// list. */

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *temp, *head, *newNode, *ptr;

// struct Node *reverse(struct Node *head)
// {
//     struct Node *l = NULL, *ptr = head, *r;

//     while (ptr != NULL)
//     {
//         r = ptr->next;
//         ptr->next = l;
//         l = ptr;
//         ptr = r;
//     }
//     return l;
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
//     int data, choice;
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
//         printf("Do you want to add more node (yes-1 & no-0):");
//         scanf("%d", &choice);
//     } while (choice == 1);

//     printf("Original Linked List :\n");
//     display(head);
//     printf("\n");
//     head = reverse(head);
//     printf("Reverse Linked List :\n");
//     display(head);
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };
// struct Node *temp, *head, *newNode, *ptr;

// struct Node *reverse(struct Node *head)
// {
//     struct Node *l = NULL, *r;
//     ptr = head;
//     while (ptr != NULL)
//     {
//         r = ptr->next;
//         ptr->next = l;
//         l = ptr;
//         ptr = r;
//     }
//     return l;
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
//     int data, choice;
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
//         printf("Do you want add more nodes (yes-1 & no-0) :");
//         scanf("%d", &choice);
//     } while (choice == 1);

//     printf("Original Linked List :\n");
//     display(head);
//     head = reverse(head);
//     printf("\nReverse Linked List :\n");
//     display(head);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *temp, *head, *newNode, *ptr;

// struct Node *reverse(struct Node *head)
// {
//     struct Node *l = NULL, *r;
//     ptr = head;
//     while (ptr != NULL)
//     {
//         r = ptr->next;
//         ptr->next = l;
//         l = ptr;
//         ptr = r;
//     }
//     return l;
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
//     int data, choice;

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
//         printf("Do you want to add more nodes(yes-1 or no-0) :");
//         scanf("%d", &choice);
//     } while (choice == 1);

//     printf("Original Linked List :\n");
//     display(head);
//     head = reverse(head);
//     printf("\nReversed Linked List :\n");
//     display(head);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *temp, *newNode, *head, *ptr;

// struct Node *reverse(struct Node *head)
// {
//     struct Node *l = NULL, *r;
//     ptr = head;
//     while (ptr != NULL)
//     {
//         r = ptr->next;
//         ptr->next = l;
//         l = ptr;
//         ptr = r;
//     }
//     return l;
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
//     int data, choice;
//     do
//     {
//         newNode = (struct Node *)malloc(sizeof(struct Node *));
//         printf("Enter the data: ");
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

//     printf("Linked List :\n");
//     display(head);

//     head = reverse(head);
//     printf("\nReverse Linek List :\n");
//     display(head);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *temp, *head, *newNode, *ptr;

struct Node *reverse(struct Node *head)
{
    ptr = head;
    struct Node *l = NULL, *r;
    while (ptr != NULL)
    {
        r = ptr->next;
        ptr->next = l;
        l = ptr;
        ptr = r;
    }
    return l;
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
        newNode = (struct Node *)malloc(sizeof(struct Node *));
        printf("Enter the data: ");
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
    head = reverse(head);
    printf("\nReversed Linked list : \n");
    display(head);
}