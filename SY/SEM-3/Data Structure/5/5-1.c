#include <stdio.h>
#include <conio.h>

struct NODE
{
     struct NODE *lchild;
     int data;
     struct NODE *rchild;
};

typedef struct NODE node;

// Create a new node and initialize
node *getnode()
{
     node *temp;
     temp = (node *)malloc(sizeof(node)); // Allocate memory
     printf("\nEnter the data: ");
     scanf("%d", &temp->data);
     temp->lchild = NULL; // Set left child to NULL
     temp->rchild = NULL; // Set right child to NULL
     return temp;
}

// Create a Binary Search Tree (BST)
node *create()
{
     int ch;
     node *root = NULL, *temp, *ptr;

     do
     {
          temp = getnode(); // Create a new node
          if (root == NULL)
               root = temp; // Set root if tree is empty
          else
          {
               ptr = root;
               while (ptr != NULL)
               {
                    if (temp->data < ptr->data)
                    {
                         if (ptr->lchild == NULL)
                         {
                              ptr->lchild = temp; // Add to left if available
                              break;
                         }
                         else
                              ptr = ptr->lchild;
                    }
                    else
                    {
                         if (ptr->rchild == NULL)
                         {
                              ptr->rchild = temp; // Add to right if available
                              break;
                         }
                         else
                              ptr = ptr->rchild;
                    }
               }
          }
          printf("\nDo you want to add more node(Y/N): ");
          ch = getche(); // Get user choice
     } while (ch == 'Y' || ch == 'y'); // Repeat if 'Y' or 'y'

     return root;
}

// Inorder traversal of the BST
void inorder(node *ptr)
{
     if (ptr != NULL)
     {
          inorder(ptr->lchild);     // Visit left subtree
          printf(" %d", ptr->data); // Print node data
          inorder(ptr->rchild);     // Visit right subtree
     }
}

// Preorder traversal of the BST
void preorder(node *ptr)
{
     if (ptr != NULL)
     {
          printf(" %d", ptr->data); // Print node data
          preorder(ptr->lchild);    // Visit left subtree
          preorder(ptr->rchild);    // Visit right subtree
     }
}

void main()
{
     int ch;
     node *root = NULL; // Initialize root
     clrscr();          // Clear screen

     while (1)
     {
          printf("\n1:Create a BST.");
          printf("\n2:Inorder of BST.");
          printf("\n3:Preorder of BST");
          printf("\n4:Exit");
          printf("\nEnter the Choice:");
          scanf("%d", &ch); // Read user choice

          switch (ch)
          {
          case 1:
               root = create(); // Create BST
               break;
          case 2:
               inorder(root); // Display inorder traversal
               break;
          case 3:
               preorder(root); // Display preorder traversal
               break;
          case 4:
               exit(0); // Exit program
          }
     }

     getch(); // Wait for user input
}
