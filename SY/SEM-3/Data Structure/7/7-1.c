#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node *left;
     struct Node *right;
};
typedef struct Node Node;

// Function to create a new node
Node *createNode(int data)
{
     Node *newNode = (Node *)malloc(sizeof(Node));
     newNode->data = data;
     newNode->left = NULL;
     newNode->right = NULL;
     return newNode;
}

// Function to insert a node into the BST
Node *insert(Node *root, int data)
{
     if (root == NULL)
     {
          return createNode(data);
     }
     if (data < root->data)
     {
          root->left = insert(root->left, data);
     }
     else
     {
          root->right = insert(root->right, data);
     }
     return root;
}

// Function to find the minimum value node in the subtree
Node *findMin(Node *root)
{
     while (root->left != NULL)
     {
          root = root->left;
     }
     return root;
}

// Function to delete a node from the BST
Node *deleteNode(Node *root, int data)
{
     if (root == NULL)
     {
          return NULL;
     }
     if (data < root->data)
     {
          root->left = deleteNode(root->left, data);
     }
     else if (data > root->data)
     {
          root->right = deleteNode(root->right, data);
     }
     else
     {
          // Node with the data found
          if (root->left == NULL)
          {
               Node *temp = root->right;
               free(root);
               return temp;
          }
          else if (root->right == NULL)
          {
               Node *temp = root->left;
               free(root);
               return temp;
          }
          Node *temp = findMin(root->right);
          root->data = temp->data;
          root->right = deleteNode(root->right, temp->data);
     }
     return root;
}

// Function to perform in-order traversal and display the BST
void inorder(Node *root)
{
     if (root != NULL)
     {
          inorder(root->left);
          printf("%d ", root->data);
          inorder(root->right);
     }
}

void main()
{
     Node *root = NULL;
     int choice, data;

     clrscr(); // Clear the screen

     while (1)
     {
          printf("\nMenu:");
          printf("\n1. Create Binary Search Tree");
          printf("\n2. Display Binary Search Tree (In-Order Traversal)");
          printf("\n3. Delete a Given Element from Binary Search Tree");
          printf("\n4. Exit");
          printf("\nEnter your choice: ");
          scanf("%d", &choice);

          switch (choice)
          {
          case 1:
               printf("\nEnter the data to be inserted into the BST: ");
               scanf("%d", &data);
               root = insert(root, data);
               break;
          case 2:
               printf("\nBinary Search Tree (In-Order Traversal): ");
               inorder(root);
               printf("\n");
               break;
          case 3:
               printf("\nEnter the data to be deleted from the BST: ");
               scanf("%d", &data);
               root = deleteNode(root, data);
               break;
          case 4:
               exit(0);
          default:
               printf("\nInvalid choice! Please enter a valid option.");
          }
     }

     getch(); // Wait for a key press
}
