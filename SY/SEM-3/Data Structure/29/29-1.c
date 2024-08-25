#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Define the structure for a node in the binary tree
struct Node
{
     int data;
     struct Node *left;
     struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
     newNode->data = data;
     newNode->left = NULL;
     newNode->right = NULL;
     return newNode;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node *root)
{
     if (root != NULL)
     {
          inorderTraversal(root->left);  // Visit left subtree
          printf("%d ", root->data);     // Print node data
          inorderTraversal(root->right); // Visit right subtree
     }
}

// Function to perform preorder traversal
void preorderTraversal(struct Node *root)
{
     if (root != NULL)
     {
          printf("%d ", root->data);      // Print node data
          preorderTraversal(root->left);  // Visit left subtree
          preorderTraversal(root->right); // Visit right subtree
     }
}

// Function to perform postorder traversal
void postorderTraversal(struct Node *root)
{
     if (root != NULL)
     {
          postorderTraversal(root->left);  // Visit left subtree
          postorderTraversal(root->right); // Visit right subtree
          printf("%d ", root->data);       // Print node data
     }
}

// Main function
int main()
{
     clrscr(); // Clear the screen
     // Creating nodes for the binary tree
     struct Node *root = createNode(1);
     root->left = createNode(2);
     root->right = createNode(3);
     root->left->left = createNode(4);
     root->left->right = createNode(5);
     root->right->left = createNode(6);
     root->right->right = createNode(7);

     // Displaying the tree traversals
     printf("Inorder Traversal: ");
     inorderTraversal(root);
     printf("\n");

     printf("Preorder Traversal: ");
     preorderTraversal(root);
     printf("\n");

     printf("Postorder Traversal: ");
     postorderTraversal(root);
     printf("\n");

     getch(); // Wait for a key press to close the console window

     return 0;
}
