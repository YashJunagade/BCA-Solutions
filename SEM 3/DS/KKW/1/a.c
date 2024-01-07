/*A) Write a menu driven program using ‘C’ for Binary Search Tree. The menu
includes
- Create a Binary Search Tree
- Insert element in a Binary Search Tree
- Display
*/

// #include <stdio.h>
// #include <stdlib.h>

// struct Tree
// {
//     int data;
//     struct Tree *left, *right;
// };

// struct Tree *newNode(int data)
// {
//     struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// struct Tree *create(struct Tree *root, int data)
// {
//     if (root == NULL)
//         return newNode(data);

//     if (root->data > data)
//         root->left = create(root->left, data);
//     else if (root->data < data)
//         root->right = create(root->right, data);

//     return root;
// }

// void display(struct Tree *root)
// {
//     if (root != NULL)
//     {
//         display(root->left);
//         printf("%d\t", root->data);
//         display(root->right);
//     }
// }

// int main()
// {
//     int data, key, choice;
//     struct Tree *root = NULL;
//     do
//     {
//         printf("\n***Choose from Following***\n");
//         printf("1. Create a Binary Search Tree\n");
//         printf("2. Insert element in a Binary Search Tree\n");
//         printf("3. Display\n");
//         printf("4. Exit\n");
//         printf("Enter your choice :");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter the data (-1 to stop): ");
//             while (1)
//             {
//                 scanf("%d", &data);
//                 if (data == -1)
//                     break;
//                 root = create(root, data);
//             }
//             break;
//         case 2:
//             printf("Enter the data you want to insert: ");
//             scanf("%d", &data);
//             root = create(root, data);
//             break;
//         case 3:
//             printf("Tree:\n");
//             display(root);
//             printf("\n");
//             break;
//         case 4:
//             printf("Thank You\n");
//             break;
//         default:
//             printf("Invalid Choice\n");
//         }
//     } while (choice != 4);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Tree
// {
//     int data;
//     struct Tree *left, *right;
// };

// struct Tree *root;

// struct Tree *newNode(int data)
// {
//     struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// struct Tree *create(struct Tree *root, int data)
// {
//     if (root == NULL)
//         return newNode(data);
//     if (root->data > data)
//         root->left = create(root->left, data);
//     else if (root->data < data)
//         root->right = create(root->right, data);

//     return root;
// }

// void display(struct Tree *root)
// {
//     if (root != NULL)
//     {
//         display(root->left);
//         printf("%d\t", root->data);
//         display(root->right);
//     }
// }

// int main()
// {
//     int choice, data;
//     struct Tree *root = NULL;
//     while (1)
//     {
//         printf("\n*** Choose from following ***\n");
//         printf("1. Create a Binary Search Tree\n");
//         printf("2. Insert element in a Binary Search Tree\n");
//         printf("3. Display\n");
//         printf("4. Exit\n");
//         printf("Enter your choice :");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter the data (-1 for stop) :");
//             while (1)
//             {
//                 scanf("%d", &data);
//                 if (data == -1)
//                     break;
//                 root = create(root, data);
//             }
//             break;
//         case 2:
//             printf("Enter the element you want to insert :");
//             scanf("%d", &data);
//             root = create(root, data);
//             break;
//         case 3:
//             display(root);
//             break;
//         case 4:
//             printf("Thank you");
//             exit(1);
//         default:
//             printf("Invalid choice");
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree *left, *right;
};

struct Tree *root, *newNode, *temp;

struct Tree *create(int data)
{
    newNode = (struct Tree *)malloc(sizeof(struct Tree));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Tree *insert(struct Tree *root, int data)
{
    if (root == NULL)
        return create(data);
    else if (root->data > data)
        root->left = insert(root->left, data);
    else if (root->data < data)
        root->right = insert(root->right, data);
    return root;
}

void display(struct Tree *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d\t", root->data);
        display(root->right);
    }
}

int main()
{
    int data, choice;

    while (1)
    {
        printf("\n*** Choose from Followig ***\n");
        printf("1. Create Binary Search Tree\n");
        printf("2. Insert elemtn In Tree\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data (-1 for stop) :");
            while (1)
            {
                scanf("%d", &data);
                if (data == -1)
                    break;
                root = insert(root, data);
            }
            break;
        case 2:
            printf("Enter element you want to insert : ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 3:
            display(root);
            break;
        case 4:
            printf("Thank You ");
            exit(1);
        default:
            printf("Invalid Choice \n");
        }
    }
    return 0;
}