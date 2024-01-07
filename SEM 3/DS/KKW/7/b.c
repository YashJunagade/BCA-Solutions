// /*B) Write a ‘C’ program to create a singly linked list and count total number of nodes
// in it and display the list and total number of Nodes.
// */

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// int countNodes(struct Node *head)
// {
//     int count = 0;
//     struct Node *ptr = head;
//     while (ptr != NULL)
//     {
//         count++;
//         ptr = ptr->next;
//     }
//     return count;
// }

// void display(struct Node *head)
// {
//     struct Node *ptr = head;
//     while (ptr != NULL)
//     {
//         printf("%d\t", ptr->data);
//         ptr = ptr->next;
//     }
// }

// int main()
// {
//     int data, choice, ans;
//     struct Node *temp, *head, *newNode;
//     temp = head = newNode = NULL;

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
//         printf("Do you want to add more nodes (yes-1 & no-0) :");
//         scanf("%d", &choice);
//     } while (choice == 1);

//     ans = countNodes(head);
//     printf("Total Nodes : %d\n", ans);
//     printf("Singly Linked List :");
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

// int countNodes(struct Node *head)
// {
//     int count = 0;
//     ptr = head;
//     while (ptr != NULL)
//     {
//         count++;
//         ptr = ptr->next;
//     }
//     return count;
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
//         printf("Do you want to add more node(yes-1 & no-0) :");
//         scanf("%d", &choice);
//     } while (choice == 1);

//     printf("Linked list :\n");
//     display(head);
//     int ans = countNodes(head);
//     printf("\nTotal nodes in singly linked list is %d", ans);

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

// void display(struct Node *head)
// {
//     ptr = head;
//     while (ptr != NULL)
//     {
//         printf("%d\t", ptr->data);
//         ptr = ptr->next;
//     }
// }

// int countNodes(struct Node *head)
// {
//     ptr = head;
//     int count = 0;
//     while (ptr != NULL)
//     {
//         count++;
//         ptr = ptr->next;
//     }
//     return count;
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
//         printf("Do you want to add more nodes(yes-1 & no-0) :");
//         scanf("%d", &choice);
//     } while (choice == 1);

//     printf("Linked list :\n");
//     display(head);

//     int ans = countNodes(head);
//     printf("\nTotal Node : %d", ans);
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

int countNode(struct Node *head)
{
    int count = 0;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
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
        printf("Do you want to add more node (yes-1 & no-0) :");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Singly Linked List :\n");
    display(head);
    int ans = countNode(head);
    printf("\nTotal Nodes are %d ", ans);
}