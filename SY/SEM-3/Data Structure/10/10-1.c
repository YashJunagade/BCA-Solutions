#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100

// Define the structure for a node in the BST
struct Node
{
     int data;
     struct Node *left;
     struct Node *right;
};

// Define a node
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

// Function to insert a node in the BST
Node *insertNode(Node *root, int data)
{
     if (root == NULL)
     {
          return createNode(data);
     }
     if (data < root->data)
     {
          root->left = insertNode(root->left, data);
     }
     else
     {
          root->right = insertNode(root->right, data);
     }
     return root;
}

// Function to print nodes level-wise
void printLevelOrder(Node *root)
{
     if (root == NULL)
          return;

     Node *queue[MAX];
     int front = 0, rear = 0;
     queue[rear++] = root;

     while (front < rear)
     {
          Node *current = queue[front++];
          printf("%d ", current->data);

          if (current->left != NULL)
          {
               queue[rear++] = current->left;
          }
          if (current->right != NULL)
          {
               queue[rear++] = current->right;
          }
     }
}

// Main function
void main()
{
     Node *root = NULL;
     int n, i, data;

     clrscr(); // Clear the screen

     printf("Enter the number of elements: ");
     scanf("%d", &n);

     printf("Enter %d integers:\n", n);
     for (i = 0; i < n; i++)
     {
          printf("Element %d: ", i + 1);
          scanf("%d", &data);
          root = insertNode(root, data);
     }

     printf("Nodes in level order:\n");
     printLevelOrder(root);

     getch(); // Wait for a key press
}
