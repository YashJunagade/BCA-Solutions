/*A) Write a ‘C’ program to read ‘n’ integers and store them in a binary Search tree
structure and count the following and display it.
- Number of nodes
- Degree of tree
- Leaf nodes
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

// int countNodes(struct Tree *root)
// {
//     if (root == NULL)
//         return 0;
//     return (1 + countNodes(root->left) + countNodes(root->right));
// }

// int degree(struct Tree *root)
// {
//     if (root == NULL)
//         return 0;

//     int leftDegree = degree(root->left);
//     int rightDegree = degree(root->right);

//     if (root->left != NULL && root->right != NULL)
//         return 2;
//     else if (root->left == NULL || root->right == NULL)
//         return 1;
//     else
//         return (leftDegree > rightDegree) ? leftDegree : rightDegree;
// }

// int countLeafNodes(struct Tree *root)
// {
//     if (root == NULL)
//         return 0;
//     else if (root->left == NULL && root->right == NULL)
//         return 1;
//     else
//         return (countLeafNodes(root->left) + countLeafNodes(root->right));
// }

// int main()
// {
//     struct Tree *root = NULL;
//     int i, n, data;
//     printf("Enter the size of the tree: ");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//     {
//         printf("Enter element %d: ", i + 1);
//         scanf("%d", &data);
//         root = create(root, data);
//     }

//     int ans = countNodes(root);
//     printf("Total number of nodes is %d\n", ans);

//     ans = degree(root);
//     printf("Degree of the tree is %d\n", ans);

//     ans = countLeafNodes(root);
//     printf("Leaf Nodes of tree is %d", ans);

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
    if (root->data > data)
        root->left = create(root->left, data);
    else if (root->data < data)
        root->right = create(root->right, data);

    return root;
}

int countNodes(struct Tree *root)
{
    if (root == NULL)
        return 0;
    return (countNodes(root->left) + countNodes(root->right) + 1);
}

int degree(struct Tree *root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL || root->right == NULL)
        return 1;
    else if (root->left != NULL && root->right != NULL)
        return 2;
    int ldegree = degree(root->left);
    int rdegree = degree(root->right);

    return (ldegree > rdegree) ? ldegree : rdegree;
}

int countLeafNode(struct Tree *root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
    {
        return (countLeafNode(root->left) + countLeafNode(root->right));
    }
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
    int data, ans;
    printf("Enter the data(-1 for stop) :");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;
        root = create(root, data);
    }

    printf("Binary Search Tree : \n");
    display(root);

    ans = countNodes(root);
    printf("\nTotal number of Nodes in tree : %d", ans);

    ans = degree(root);
    printf("\nDegree of Tree : %d", ans);

    ans = countLeafNode(root);
    printf("\nCount Leaf Node : %d", ans);

    return 0;
}