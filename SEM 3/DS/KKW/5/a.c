/*A)Write a menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Traverse it by using Inorder and Preorder traversing technique*/

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

// void inorderTraverse(struct Tree *root)
// {
//     if (root != NULL)
//     {
//         inorderTraverse(root->left);
//         printf("%d\t", root->data);
//         inorderTraverse(root->right);
//     }
// }

// void postorderTraverse(struct Tree *root)
// {
//     if (root != NULL)
//     {
//         postorderTraverse(root->left);
//         postorderTraverse(root->right);
//         printf("%d\t", root->data);
//     }
// }

// int main()
// {
//     int choice, data;
//     struct Tree *root = NULL;

//     do
//     {
//         printf("\n***Choose from the following***\n");
//         printf("1. Create Binary Search Tree :\n");
//         printf("2. Inorder Traverse \n");
//         printf("3. Postorder Traverse \n");
//         printf("4. Exit\n");
//         printf("Enter your choice :");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter the data(-1 for stop):");
//             while (1)
//             {
//                 scanf("%d", &data);
//                 if (data == -1)
//                     break;
//                 root = create(root, data);
//             }
//             break;
//         case 2:
//             printf("Inorder Traverse Tree :\n");
//             inorderTraverse(root);
//             break;
//         case 3:
//             printf("Postorder Traverse Tree :\n");
//             postorderTraverse(root);
//             break;
//         case 4:
//             printf("Thank you");
//             break;
//         default:
//             printf("Invalid choice ");
//         }
//     } while (choice != 4);
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

// void preorderTraverse(struct Tree *root)
// {
//     if (root != NULL)
//     {
//         printf("%d\t", root->data);
//         preorderTraverse(root->left);
//         preorderTraverse(root->right);
//     }
// }

// void inorderTraverse(struct Tree *root)
// {
//     if (root != NULL)
//     {
//         inorderTraverse(root->left);
//         printf("%d\t", root->data);
//         inorderTraverse(root->right);
//     }
// }

// int main()
// {
//     int choice, data;
//     while (1)
//     {
//         printf("\n*** Choose from following ***\n");
//         printf("1. Create Binary Search Tree \n");
//         printf("2. Inorder Traverse\n");
//         printf("3. Preorder Traverse\n");
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
//             inorderTraverse(root);
//             break;
//         case 3:
//             preorderTraverse(root);
//             break;
//         case 4:
//             printf("Thank you");
//             exit(1);
//             break;
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

struct Tree *root;

struct Tree *newNode(int data)
{
    struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Tree *create(struct Tree *root, int data)
{
    if (root == NULL)
        return newNode(data);
    else if (root->data > data)
        root->left = create(root->left, data);
    else if (root->data < data)
        root->right = create(root->right, data);

    return root;
}

void inorderTraverse(struct Tree *root)
{
    if (root != NULL)
    {
        inorderTraverse(root->left);
        printf("%d\t", root->data);
        inorderTraverse(root->right);
    }
}

void preorderTraverse(struct Tree *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }
}

int main()
{
    int data, choice;
    while (1)
    {
        printf("\n*** Choose From Following ****\n");
        printf("1. Create a Binary Search Tree\n");
        printf("2. Inorder Traverse\n");
        printf("3. Preorder Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data(-1 for stop) :");
            while (1)
            {
                scanf("%d", &data);
                if (data == -1)
                    break;
                root = create(root, data);
            }
            break;
        case 2:
            printf("Inorder Traverse :\n");
            inorderTraverse(root);
            break;
        case 3:
            printf("Perorder Traverse :\n");
            preorderTraverse(root);
            break;
        case 4:
            printf("Thank You");
            exit(1);
            break;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
