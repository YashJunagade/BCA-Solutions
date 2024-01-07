/*A) Write a menu driven program using ‘C’ for singly linked list-
- To create linked list.
- To display linked list
- To insert node at last position of linked list.
- To delete node from specific position of linked list*/

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *temp, *head, *newNode, *ptr, *temp;

// void create()
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
// }

// void insertAtLast(struct Node *head, int data)
// {
//     newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     ptr = head;

//     while (ptr->next != NULL)
//         ptr = ptr->next;

//     ptr->next = newNode;
// }

// void deleteSpecNode(struct Node *head, int data)
// {
//     ptr = head;
//     while (ptr->next->data != data)
//         ptr = ptr->next;

//     temp = ptr->next;
//     ptr->next = temp->next;
//     free(temp);
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
//     int choice, data;
//     do
//     {
//         printf("\n*** Choose from following***\n");
//         printf("1. create linked list\n");
//         printf("2. display linked list\n");
//         printf("3. insert node at last position of linked list\n");
//         printf("4. delete node from specific position of linked list\n");
//         printf("5. Exit\n");
//         printf("Enter the choice :");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             create();
//             break;
//         case 2:
//             printf("\nLinked List :\n");
//             display(head);
//             break;
//         case 3:
//             printf("Enter the element you want to add at last in linked list :");
//             scanf("%d", &data);
//             insertAtLast(head, data);
//             break;
//         case 4:
//             printf("Enter the position of linked list you want to delete :");
//             scanf("%d", &data);
//             deleteSpecNode(head, data);
//             break;
//         case 5:
//             printf("Thank You");
//             break;
//         default:
//             printf("Invalid Choice");
//         }
//     } while (choice != 5);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *temp, *head, *newNode, *ptr, *temp;

struct Node *create()
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

struct Node *insertAtLast(struct Node *head, int data)
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
    return head;
}

struct Node *deleteSpecPos(struct Node *head, int data)
{
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next->data == data)
            break;
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return head;
}

int main()
{
    int data, choice;
    while (1)
    {
        printf("\n*** Choose from following***\n");
        printf("1. create linked list\n");
        printf("2. display linked list\n");
        printf("3. insert node at last position of linked list\n");
        printf("4. delete node from specific position of linked list\n");
        printf("5. Exit\n");
        printf("Enter the choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create();
            break;
        case 2:
            printf("Linked List :\n");
            display(head);
            break;
        case 3:
            printf("Enter the element you want to add last :");
            scanf("%d", &data);
            head = insertAtLast(head, data);
            break;
        case 4:
            printf("Enter the element you want to delete :");
            scanf("%d", &data);
            head = deleteSpecPos(head, data);
            break;
        case 5:
            printf("Thank You");
            exit(1);
        default:
            printf("Invalid Choice");
        }
    }
    return 0;
}