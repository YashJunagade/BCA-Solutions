/*A) Write a ‘C’ program to create a Binary Search tree and implements following
functions
- Create Binary Search Tree
- Search a node in binary search tree
- Display a binary search tree (Post order Traversal)
*/

#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree *left, *right;
};

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
    if (root->data > data)
        root->left = create(root->left, data);
    else if (root->data < data)
        root->right = create(root->right, data);
    return root;
}

int search(struct Tree *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    else if (root->data > key)
        return search(root->left, key);
    else if (root->data < key)
        return search(root->right, key);
    return 0;
}

// Postorder traverse
void display(struct Tree *root)
{
    if (root != NULL)
    {
        display(root->left);
        display(root->right);
        printf("%d\t", root->data);
    }
}

int main()
{
    struct Tree *root = NULL;
    int data;
    printf("Enter the data (-1 for stop):");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;
        root = create(root, data);
    }

    printf("Binary Search Tree :\n");
    display(root);

    printf("\nEnter the element you want to search :");
    scanf("%d", &data);
    if (search(root, data))
        printf("%d is found ", data);
    else
        printf("%d is not found", data);
    return 0;
}