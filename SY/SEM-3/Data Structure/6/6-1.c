#include <stdio.h>
#include <conio.h>

struct NODE
{
     struct NODE *lchild; // Pointer to left child
     int data;            // Node data
     struct NODE *rchild; // Pointer to right child
};

typedef struct NODE node;

// Create and initialize a new node
node *getnode()
{
     node *temp;
     temp = (node *)malloc(sizeof(node)); // Allocate memory
     printf("\nEnter the data: ");
     scanf("%d", &temp->data); // Read node data
     temp->lchild = NULL;      // Initialize left child
     temp->rchild = NULL;      // Initialize right child
     return temp;
}

// Create a Binary Search Tree (BST)
node *create()
{
     int ch;
     node *root = NULL, *temp, *ptr;

     do
     {
          temp = getnode(); // Create new node
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
                              ptr->lchild = temp; // Add to left child
                              break;
                         }
                         else
                              ptr = ptr->lchild; // Move to left child
                    }
                    else
                    {
                         if (ptr->rchild == NULL)
                         {
                              ptr->rchild = temp; // Add to right child
                              break;
                         }
                         else
                              ptr = ptr->rchild; // Move to right child
                    }
               }
          }
          printf("\nDo you want to add more node(Y/N): ");
          ch = getche(); // Read user choice
     } while (ch == 'Y' || ch == 'y'); // Continue if 'Y' or 'y'

     return root;
}

// Postorder traversal of the BST
void postorder(node *ptr)
{
     if (ptr != NULL)
     {
          postorder(ptr->lchild);   // Visit left subtree
          postorder(ptr->rchild);   // Visit right subtree
          printf(" %d", ptr->data); // Print node data
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
          printf("\n2:Preorder of BST.");
          printf("\n3:Postorder of BST");
          printf("\n4:Exit");
          printf("\nEnter the Choice:");
          scanf("%d", &ch); // Read user choice

          switch (ch)
          {
          case 1:
               root = create(); // Create BST
               break;
          case 2:
               preorder(root); // Display preorder traversal
               break;
          case 3:
               postorder(root); // Display postorder traversal
               break;
          case 4:
               exit(0); // Exit program
          }
     }

     getch(); // Wait for user input
}
