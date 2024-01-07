/*A) Write menu driven program using ‘C’ for Binary Search Tree. The menu includes
- Create a Binary Search Tree
- Display
- Search the element in Binary Search Tree*/

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
//     else if (root->data > data)
//         root->left = create(root->left, data);
//     else if (root->data < data)
//         root->right = create(root->right, data);

//     return root;
// }

// struct Tree *search(struct Tree *root, int key)
// {
//     if (root == NULL || root->data == key)
//         return root;
//     else if (root->data > key)
//         return search(root->left, key);
//     else if (root->data < key)
//         return search(root->right, key);
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
//     int data, choice;
//     while (1)
//     {
//         printf("\n*** Choose from followin ***\n");
//         printf("1. Create Binary Search Tree\n");
//         printf("2. Display\n");
//         printf("3. Search Element in BST\n");
//         printf("4. Exit\n");
//         printf("Enter your choice :");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter the data(-1 for stop) :");
//             while (1)
//             {
//                 scanf("%d", &data);
//                 if (data == -1)
//                     break;
//                 root = create(root, data);
//             }
//             break;
//         case 2:
//             printf("Binary Search Tree :\n");
//             display(root);
//             break;
//         case 3:
//             printf("Enter the element you want to search :");
//             scanf("%d", &data);
//             if (search(root, data) == NULL)
//                 printf("%d is not found in tree", data);
//             else
//                 printf("%d is found in tree", data);
//             break;
//         case 4:
//             printf("Thank you");
//             exit(1);
//         default:
//             printf("Invalid Choice");
//         }
//     }
//     return 0;

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

struct Tree *search(struct Tree *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    else if (root->data > key)
        return search(root->left, key);
    else if (root->data < key)
        return search(root->right, key);
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
    int choice, data;

    while (1)
    {
        printf("\n\n\n*** Choose from following***\n");
        printf("1. Create A BST\n");
        printf("2. Display\n");
        printf("3. Search In BST\n");
        printf("4. Exit\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data (-1 for Stop) : ");
            while (1)
            {
                scanf("%d", &data);
                if (data == -1)
                    break;
                root = create(root, data);
            }
            break;
        case 2:
            printf("Binary Search Tree : \n");
            display(root);
            break;
        case 3:
            printf("Enter Element You Want To Search :");
            scanf("%d", &data);
            if (search(root, data) == NULL)
                printf("%d is not found", data);
            else
                printf("%d is found", data);
            break;
        case 4:
            printf("Thank You");
            exit(1);
            break;
        default:
            printf("Invalid Choice");
        }
    }
}