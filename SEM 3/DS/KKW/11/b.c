// /*B) Write a menu driven program using ‘C’ for Dynamic implementation of Queue for
// integers. The menu includes
// - Insert
// - Delete
// - Display
// - Exit
// */

// #include <stdio.h>
// #include <stdlib.h>

// struct Queue
// {
//     int data;
//     struct Queue *next;
// };

// struct Queue *f, *r;

// struct Queue *insert(int data)
// {
//     struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
//     newNode->data = data;
//     newNode->next = NULL;
//     if (f == NULL)
//         f = r = newNode;
//     else
//     {
//         r->next = newNode;
//         r = newNode;
//     }
//     return f;
// }

// int delete()
// {
//     int x = -1;
//     struct Queue *temp = f;
//     if (f == NULL)
//         printf("Queue is empty");
//     else
//     {
//         x = f->data;
//         f = f->next;
//         free(temp);
//     }
//     return x;
// }

// void display(struct Queue *f)
// {
//     struct Queue *ptr = f;
//     if (f == NULL)
//         printf("Queue is empty");
//     while (ptr != NULL)
//     {
//         printf("%d\t", ptr->data);
//         ptr = ptr->next;
//     }
// }

// int main()
// {
//     while (1)
//     {
//         int choice, data, ans;
//         struct Queue *q = NULL;
//         printf("\n*** Choose from following ***\n");
//         printf("1. Insert \n2. Delete \n3. Display \n4. Exit\n");
//         printf("Enter your choice :");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             do
//             {
//                 printf("\nEnter data : ");
//                 scanf("%d", &data);
//                 q = insert(data);
//                 printf("Do you want to add more node in queue(yes-1 & no-0) :");
//                 scanf("%d", &choice);
//             } while (choice == 1);
//             break;
//         case 2:
//             ans = delete ();
//             if (ans != -1)
//                 printf("delete %d from queue", ans);
//             else
//                 printf("\nno data is delete from queue");
//             break;
//         case 3:
//             printf("Queue :");
//             display(f);
//             break;
//         case 4:
//             printf("Thank you");
//             exit(1);
//         }
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Queue
// {
//     int data;
//     struct Queue *next;
// };
// struct Queue *f, *r;

// struct Queue *insert(int data)
// {
//     struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (f == NULL)
//         f = r = newNode;
//     else
//     {
//         r->next = newNode;
//         r = newNode;
//     }
//     return f;
// }
// struct Queue *delete(struct Queue *f)
// {
//     struct Queue *temp = f;
//     if (f == NULL)
//         printf("Queue is empty");
//     else
//     {
//         f = f->next;
//         free(temp);
//         return f;
//     }
// }

// void display(struct Queue *f)
// {
//     while (f != NULL)
//     {
//         printf("%d\t", f->data);
//         f = f->next;
//     }
// }

// int main()
// {
//     int choice, data;
//     while (1)
//     {
//         printf("\n*** Choose from following ***\n");
//         printf("1. Insert\n");
//         printf("2. Delete\n");
//         printf("3. Display\n");
//         printf("4. Exit\n");
//         printf("Enter your choice :");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             do
//             {
//                 printf("Enter the element you want to insert in Queue :");
//                 scanf("%d", &data);
//                 f = insert(data);
//                 printf("Do you want to insert more element(yes-1 & no-0) :");
//                 scanf("%d", &choice);
//             } while (choice == 1);

//             break;

//         case 2:
//             f = delete (f);
//             break;
//         case 3:
//             display(f);
//             break;
//         case 4:
//             printf("Thank You");
//             exit(1);
//         default:
//             printf("Invalid Option");
//         }
//     }
//     return 0;
// }

// - Insert
// - Delete
// - Display
// - Exit

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *f, *r, *ptr, *newNode;

struct Queue *insert(int data)
{
    newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->data = data;
    newNode->next = NULL;

    if (f == NULL)
        f = r = newNode;
    else
    {
        r->next = newNode;
        r = newNode;
    }
    return f;
}

struct Queue *delete(struct Queue *f)
{
    struct Queue *temp;
    if (f == NULL)
        printf("Queue is empty");
    else
    {
        temp = f;
        f = f->next;
    }
    return f;
}

void display(struct Queue *f)
{
    while (f != NULL)
    {
        printf("%d\t", f->data);
        f = f->next;
    }
}

int main()
{
    int data, choice;

    while (1)
    {
        printf("\n*** Choose From Following ***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                printf("Enter the data :");
                scanf("%d", &data);
                f = insert(data);
                printf("Do you want to add more node(yes-1 & no-0) :");
                scanf("%d", &choice);
            } while (choice == 1);
            break;
        case 2:
            f = delete (f);
            printf("Element are deleted");
            break;
        case 3:
            printf("Queue :");
            display(f);
            break;
        case 4:
            printf("Thank You");
            exit(1);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}