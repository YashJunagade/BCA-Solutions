/*A) Write menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Display
- Delete a given element from Binary Search Tree
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

// int minV(struct Tree *root)
// {
//     int min = root->data;
//     while (root->left = NULL)
//     {
//         min = root->data;
//         root = root->left;
//     }
//     return min;
// }

// struct Tree *delete(struct Tree *root, int key)
// {
//     if (root == NULL)
//         return root;
//     else if (root->data > key)
//         root->left = delete (root->left, key);
//     else if (root->data < key)
//         root->right = delete (root->right, key);
//     else
//     {
//         if (root->left == NULL)
//             return root->right;
//         else if (root->right == NULL)
//             return root->left;
//         else
//         {
//             root->data = minV(root->left);
//             root->right = delete (root->right, root->data);
//         }
//     }
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
//     int choice, data, key;
//     struct Tree *root = NULL;

//     do
//     {
//         printf("\n***Choose from Following***\n");
//         printf("1. Create Binary Search Tree \n");
//         printf("2. Display \n");
//         printf("3. Delete From Binary Search Tree\n");
//         printf("4. Exit\n");
//         printf("Enter your choice :");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter the data (-1 for NULL) :");
//             while (1)
//             {
//                 scanf("%d", &data);
//                 if (data == -1)
//                     break;
//                 root = create(root, data);
//             }
//             break;

//         case 2:
//             display(root);
//             break;

//         case 3:
//             printf("Enter a element you want to delete :");
//             scanf("%d", &key);
//             root = delete (root, key);
//             break;

//         case 4:
//             printf("Thank you");
//             break;

//         default:
//             printf("Invalid Choice");
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

// int minValue(struct Tree *root)
// {
//     int min = root->data;
//     while (root->left != NULL)
//     {
//         min = root->data;
//         root = root->left;
//     }
//     return min;
// }

// struct Tree *delete(struct Tree *root, int key)
// {
//     if (root == NULL)
//         return root;
//     if (root->data > key)
//         root->left = delete (root->left, key);
//     else if (root->data < key)
//         root->right = delete (root->right, key);
//     else
//     {
//         if (root->left == NULL)
//             return root->right;
//         else if (root->right == NULL)
//             return root->left;
//         else
//         {
//             root->data = minValue(root->right);
//             root->right = delete (root->right, root->data);
//         }
//     }
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
//     int data, choice, key;

//     while (1)
//     {
//         printf("\n*** Choose from following ***\n");
//         printf("1. Create Binary Search Tree\n");
//         printf("2. Display\n");
//         printf("3. Delete from BST\n");
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
//             display(root);
//             break;
//         case 3:
//             printf("Enter the element you want to delete :");
//             scanf("%d", &key);

//             root = delete (root, key);
//             break;
//         case 4:
//             printf("Thank you ");
//             exit(1);
//             break;
//         default:
//             printf("Invalid Choice");
//         }
//     }
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

int minV(struct Tree *root)
{
    int minValue = root->data;
    while (root->left != NULL)
    {
        minValue = root->data;
        root = root->left;
    }
    return minValue;
}

struct Tree *delete(struct Tree *root, int key)
{
    if (root == NULL)
        return root;
    else if (root->data > key)
        root->left = delete (root->left, key);
    else if (root->data < key)
        root->right = delete (root->right, key);
    else
    {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else
        {
            root->data = minV(root->right);
            root->right = delete (root->right, root->data);
        }
    }
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
        printf("\n*** Choose from Following ***\n");
        printf("1. Create Binary Search Tree\n");
        printf("2. Display\n");
        printf("3. Delete element from tree\n");
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
                root = create(root, data);
            }
            break;
        case 2:
            printf("Binary Search Tree :\n");
            display(root);
            break;
        case 3:
            printf("Enter the elemen you want to delete :");
            scanf("%d", &data);
            root = delete (root, data);
            break;
        case 4:
            printf("Thank you");
            exit(1);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}