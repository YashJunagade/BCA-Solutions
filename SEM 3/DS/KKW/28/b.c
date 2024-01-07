/*B) Write a ‘C’ program to read n integers and create two lists such that all positive
numbers are in one list and negative numbers are in another list. Display both the lists.
*/

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *insert(struct Node *head, int data)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (head == NULL)
//         return newNode;

//     struct Node *temp = head;
//     while (temp->next != NULL)
//         temp = temp->next;

//     temp->next = newNode;

//     return head;
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
//     int data, n;
//     struct Node *head1 = NULL, *head2 = NULL;

//     printf("Enter the number of nodes you want to store: ");
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter node element %d: ", i + 1);
//         scanf("%d", &data);

//         if (data > 0)
//             head1 = insert(head1, data);
//         else
//             head2 = insert(head2, data);
//     }

//     printf("Positive Number Linked List:\n");
//     display(head1);
//     printf("\nNegative Number Linked List:\n");
//     display(head2);

//     return 0;
// }

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