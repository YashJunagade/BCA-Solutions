#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct NODE
{
     int data;
     struct NODE *left, *right;
};

typedef struct NODE node;

// Function to create a new node
node *createNode(int data)
{
     node *newNode = (node *)malloc(sizeof(node));
     newNode->data = data;
     newNode->left = newNode->right = NULL;
     return newNode;
}

// Function to insert a node into the BST
node *insert(node *root, int data)
{
     if (root == NULL)
     {
          root = createNode(data);
     }
     else if (data < root->data)
     {
          root->left = insert(root->left, data);
     }
     else
     {
          root->right = insert(root->right, data);
     }
     return root;
}

// Function to count the number of nodes in the BST
int countNodes(node *root)
{
     if (root == NULL)
          return 0;
     return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the number of leaf nodes in the BST
int countLeafNodes(node *root)
{
     if (root == NULL)
          return 0;
     if (root->left == NULL && root->right == NULL)
          return 1;
     return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to find the degree of the tree
int findDegree(node *root)
{
     if (root == NULL)
          return 0;
     int leftDegree = findDegree(root->left);
     int rightDegree = findDegree(root->right);
     return (root->left ? 1 : 0) + (root->right ? 1 : 0) + leftDegree + rightDegree;
}

// Main function
void main()
{
     node *root = NULL;
     int n, data;

     clrscr(); // Clear the screen

     // Accept the number of elements
     printf("Enter the number of elements: ");
     scanf("%d", &n);

     // Accept the elements and insert them into the BST
     for (int i = 0; i < n; i++)
     {
          printf("Enter element %d: ", i + 1);
          scanf("%d", &data);
          root = insert(root, data);
     }

     // Count and display results
     printf("\nNumber of nodes: %d", countNodes(root));
     printf("\nDegree of the tree: %d", findDegree(root));
     printf("\nNumber of leaf nodes: %d", countLeafNodes(root));

     getch(); // Wait for a key press before exiting
}
