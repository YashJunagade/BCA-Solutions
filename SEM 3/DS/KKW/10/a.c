// /*A) Write a ‘C’ program to read ‘n’ integers and store them in a Binary search tree and
// display the nodes level wise.*/

// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure of a node in the BST
// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
// };

// // Function to create a new node
// struct Node *createNode(int value)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = value;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// // Function to insert a node in the BST
// struct Node *insert(struct Node *root, int value)
// {
//     if (root == NULL)
//         return createNode(value);

//     if (value < root->data)
//         root->left = insert(root->left, value);
//     else if (value > root->data)
//         root->right = insert(root->right, value);

//     return root;
// }

// // Function to print nodes at a specific level
// void printLevel(struct Node *root, int level)
// {
//     if (root == NULL)
//         return;

//     if (level == 1)
//     {
//         printf("%d ", root->data);
//     }
//     else if (level > 1)
//     {
//         printLevel(root->left, level - 1);
//         printLevel(root->right, level - 1);
//     }
// }

// int max(int x, int y)
// {
//     if (x > y)
//         return x;
//     else
//         return y;
// }

// // Function to find the height (depth) of the BST
// int height(struct Node *node)
// {
//     if (node == NULL)
//         return 0;
//     return max(height(node->left), height(node->left) + 1);
// }

// // Function to print nodes level-wise
// void printLevelOrder(struct Node *root)
// {
//     int h = height(root);
//     for (int i = 1; i <= h; i++)
//     {
//         printf("Level %d: ", i);
//         printLevel(root, i);
//         printf("\n");
//     }
// }

// int main()
// {
//     struct Node *root = NULL;
//     int n, value;

//     printf("Enter the size : ");
//     scanf("%d", &n);

//     printf("Enter %d integers:\n", n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &value);
//         root = insert(root, value);
//     }

//     printf("Nodes level-wise:\n");
//     printLevelOrder(root);

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

// int max(int x, int y)
// {
//     if (x > y)
//         return x;
//     else
//         return y;
// }

// int height(struct Tree *root)
// {
//     if (root == NULL)
//         return 0;
//     return max(height(root->left), height(root->right) + 1);
// }

// void printLevel(struct Tree *root, int level)
// {
//     if (root == NULL)
//         return;
//     if (level == 1)
//         printf("%d \t", root->data);
//     else if (level > 1)
//     {
//         printLevel(root->left, level - 1);
//         printLevel(root->right, level - 1);
//     }
// }

// void printLevelOrder(struct Tree *root)
// {
//     int i, h = height(root);
//     for (i = 1; i <= h; i++)
//     {
//         printf("Level %d :", i);
//         printLevel(root, i);
//         printf("\n");
//     }
// }

// int main()
// {
//     int data;
//     printf("Enter the data(-1 for stop) :");
//     while (1)
//     {
//         scanf("%d", &data);
//         if (data == -1)
//             break;
//         root = create(root, data);
//     }

//     printLevelOrder(root);
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

// int max(int x, int y)
// {
//     if (x > y)
//         return x;
//     else
//         return y;
// }

// int height(struct Tree *root)
// {
//     if (root == NULL)
//         return 0;
//     return max(height(root->left), height(root->right) + 1);
// }

// void printLevelOrder(struct Tree *root, int level)
// {
//     if (root == NULL)
//         return;
//     if (level == 1)
//         printf("%d\t", root->data);
//     else if (level > 1)
//     {
//         printLevelOrder(root->left, level - 1);
//         printLevelOrder(root->right, level - 1);
//     }
// }

// void printLevel(struct Tree *root)
// {
//     int i, h = height(root);
//     for (i = 1; i <= h; i++)
//     {
//         printf("Level %d :", i);
//         printLevelOrder(root, i);
//         printf("\n");
//     }
// }

// int main()
// {
//     int data;
//     printf("Enter the data (-1 for stop):");
//     while (1)
//     {
//         scanf("%d", &data);
//         if (data == -1)
//             break;
//         root = create(root, data);
//     }

//     printLevel(root);
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
//     else if (root->data > data)
//         root->left = create(root->left, data);
//     else if (root->data < data)
//         root->right = create(root->right, data);

//     return root;
// }

// int max(int x, int y)
// {
//     if (x > y)
//         return x;
//     else
//         return y;
// }

// int height(struct Tree *root)
// {
//     if (root == NULL)
//         return 0;
//     return max(1 + height(root->left), height(root->right));
// }

// void printLevel(struct Tree *root, int level)
// {
//     if (root == NULL)
//         return;
//     else if (level == 1)
//         printf("%d\t", root->data);
//     else
//     {
//         printLevel(root->left, level - 1);
//         printLevel(root->right, level - 1);
//     }
// }

// void printLevelNode(struct Tree *root)
// {
//     int i, h = height(root);
//     for (i = 1; i <= h; i++)
//     {
//         printf("Level %d :", i);
//         printLevel(root, i);
//         printf("\n");
//     }
// }

// int main()
// {
//     int data;
//     printf("Enter the data (-1 for stop) :");
//     while (1)
//     {
//         scanf("%d", &data);
//         if (data == -1)
//             break;
//         root = create(root, data);
//     }

//     printLevelNode(root);
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

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int height(struct Tree *root)
{
    if (root == NULL)
        return 0;
    return max(1 + height(root->left), height(root->right));
}

void printLevel(struct Tree *root, int level)
{
    if (root == NULL)
        return;
    else if (level == 1)
    {
        printf("%d ", root->data);
    }
    else
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void printLevelNode(struct Tree *root)
{
    int i, h = height(root);
    for (i = 1; i <= h; i++)
    {
        printf("Level %d :", i);
        printLevel(root, i);
        printf("\n");
    }
}

int main()
{
    int data;
    printf("Enter the data (-1 for stop) :");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;
        root = create(root, data);
    }

    printLevelNode(root);
}