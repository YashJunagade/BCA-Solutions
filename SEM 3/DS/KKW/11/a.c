// /*A) Write a menu driven program using ‘C’ for singly linked list-
// - To create linked list.
// - To display linked list
// - To search node in linked list.
// - Insert at last position*/

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *head, *temp, *newNode, *ptr;

// struct Node *getNode()
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
//         printf("Do you want to add more nodes (yes-1 & no-0):");
//         scanf("%d", &choice);
//     } while (choice == 1);
// }

// void insertAtLast(struct Node *head, int data)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     ptr = head;
//     while (ptr->next != NULL)
//         ptr = ptr->next;

//     ptr->next = newNode;
// }

// void search(struct Node *head, int key)
// {
//     ptr = head;
//     int flag = 0;
//     while (ptr != NULL)
//     {
//         if (ptr->data == key)
//             flag = 1;
//         ptr = ptr->next;
//     }
//     if (flag == 1)
//         printf("%d is found", key);
//     else
//         printf("%d is not found", key);
// }

// void display()
// {
//     ptr = head;
//     printf("\nLinked List is: \n");
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
//         printf("\n***Choose from following***\n");
//         printf("1. create linked list\n");
//         printf("2. display linked list\n");
//         printf("3. search node in linked list\n");
//         printf("4. Insert at last position\n");
//         printf("5. Exit\n");
//         printf("Enter your choice :");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             getNode();
//             break;
//         case 2:
//             display(head);
//             break;
//         case 3:
//             printf("Enter the data you want to search :");
//             scanf("%d", &data);
//             search(head, data);
//             break;
//         case 4:
//             printf("Enter the data you want to add last:");
//             scanf("%d", &data);
//             insertAtLast(head, data);
//             break;
//         case 5:
//             printf("Thank You ");
//             break;
//         default:
//             printf("Invalide choice");
//         }
//     } while (choice != 5);
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *temp, *head, *newNode, *ptr;

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
        printf("Do you want to add more node(yes-1 & no-0) :");
        scanf("%d", &choice);
    } while (choice == 1);
}

int search(struct Node *head, int key)
{
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == key)
            return 1;
        ptr = ptr->next;
    }
    return -1;
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

void display(struct Node *head)
{
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int data, choice, key;

    while (1)
    {
        printf("\n*** Choose From Following ***\n");
        printf("1. create linked list.\n");
        printf("2. display linked list\n");
        printf("3. search node in linked list.\n");
        printf("4. Insert at last position\n");
        printf("5. Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            printf("Linked List :\n");
            display(head);
            break;
        case 3:
            printf("Enter the element you want to search :");
            scanf("%d", &key);
            if (search(head, key) == -1)
                printf("%d is not found", key);
            else
                printf("%d is found", key);
            break;
        case 4:
            printf("Enter the data you want to add at last :");
            scanf("%d", &key);
            head = insertAtLast(head, key);
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