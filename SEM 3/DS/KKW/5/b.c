/*B) Write a ‘C’ program to create a linked list with a given number in which data part
of each node contains an individual digit of the number.
(Ex. Suppose the number is 368 then the nodes of linked list should contain 3, 6, 8)
*/

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *insertAtBeg(struct Node *head, int data)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (head == NULL)
//     {
//         head = newNode;
//     }
//     else
//     {
//         newNode->next = head;
//         head = newNode;
//     }
//     return head;
// }

// void display(struct Node *head)
// {
//     while (head != NULL)
//     {
//         printf("%d\t", head->data);
//         head = head->next;
//     }
// }

// int main()
// {
//     int num, digit;
//     struct Node *head = NULL;
//     printf("Enter the data :");
//     scanf("%d", &num);

//     while (num > 0)
//     {
//         digit = num % 10;
//         num = num / 10;
//         head = insertAtBeg(head, digit);
//     }
//     printf("Linked list :\n");
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

// struct Node *head, *newNode, *temp, *ptr;

// struct Node *create(struct Node *head, int data)
// {
//     newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (head == NULL)
//         head = newNode;
//     else
//     {
//         newNode->next = head;
//         head = newNode;
//     }
//     return newNode;
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
//     int num, digit;

//     printf("Enter the number :");
//     scanf("%d", &num);

//     while (num > 0)
//     {
//         digit = num % 10;
//         num = num / 10;
//         head = create(head, digit);
//     }

//     printf("Linked List :\n");
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

// struct Node *head, *newNode, *ptr;

// struct Node *insertAtBeg(struct Node *head, int data)
// {
//     newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (head == NULL)
//         head = newNode;
//     else
//     {
//         newNode->next = head;
//         head = newNode;
//     }
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
//     int num, digit;
//     printf("Enter Number :");
//     scanf("%d", &num);

//     while (num > 0)
//     {
//         digit = num % 10;
//         num = num / 10;
//         head = insertAtBeg(head, digit);
//     }
//     printf("Linked list :\n");
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

struct Node *head, *newNode, *ptr;

struct Node *create(int data)
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
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
    int digit, num;
    printf("Enter number :");
    scanf("%d", &num);

    while (num > 0)
    {
        digit = num % 10;
        num = num / 10;
        head = create(digit);
    }

    printf("Linked list :");
    display(head);
    return 0;
}