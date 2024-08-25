#include <stdio.h>
#include <stdlib.h>

struct Tree
{
     int data;
     struct Tree *left, *right;
};

// Function to create a new tree node
struct Tree *newNode(int data)
{
     struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
     newNode->data = data;
     newNode->left = newNode->right = NULL;
     return newNode;
}

// Function to insert a new node into the BST
struct Tree *create(struct Tree *root, int data)
{
     if (root == NULL)
     {
          return newNode(data);
     }
     if (data < root->data)
     {
          root->left = create(root->left, data);
     }
     else if (data > root->data)
     {
          root->right = create(root->right, data);
     }
     return root;
}

// Function to search for a value in the BST
int search(struct Tree *root, int key)
{
     if (root == NULL)
     {
          return 0;
     }
     if (root->data == key)
     {
          return 1;
     }
     else if (key < root->data)
     {
          return search(root->left, key);
     }
     else
     {
          return search(root->right, key);
     }
}

// Function to display the tree nodes in post-order
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

     printf("Enter the data (-1 to stop):\n");
     while (1)
     {
          scanf("%d", &data);
          if (data == -1)
               break;
          root = create(root, data);
     }

     printf("Binary Search Tree (Post-order Traversal):\n");
     display(root);

     printf("\nEnter the element you want to search: ");
     scanf("%d", &data);
     if (search(root, data))
     {
          printf("%d is found\n", data);
     }
     else
     {
          printf("%d is not found\n", data);
     }

     return 0;
}
