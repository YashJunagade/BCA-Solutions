#include <stdio.h>
#include <stdlib.h> // For malloc and exit
#include <conio.h>  // For clrscr and getche

// Structure for a tree node
struct NODE
{
     struct NODE *lchild; // Left child
     int data;            // Node data
     struct NODE *rchild; // Right child
};

typedef struct NODE node; // Node alias

// Create a new node
node *getnode()
{
     node *temp;
     temp = (node *)malloc(sizeof(node)); // Allocate memory
     if (temp == NULL)
     {
          printf("Memory allocation failed\n");
          exit(1); // Exit if memory allocation fails
     }
     printf("\nEnter the data: ");
     scanf("%d", &temp->data); // Input data
     temp->lchild = NULL;      // Initialize left child
     temp->rchild = NULL;      // Initialize right child
     return temp;
}

// Create a BST
node *create()
{
     int ch;
     node *root = NULL, *temp, *ptr;

     do
     {
          temp = getnode(); // Create a new node
          if (root == NULL)
          {
               root = temp; // Set as root if tree is empty
          }
          else
          {
               ptr = root;
               while (ptr != NULL)
               {
                    if (temp->data < ptr->data)
                    {
                         if (ptr->lchild == NULL)
                         {
                              ptr->lchild = temp; // Insert as left child
                              break;
                         }
                         else
                         {
                              ptr = ptr->lchild; // Move to left child
                         }
                    }
                    else
                    {
                         if (ptr->rchild == NULL)
                         {
                              ptr->rchild = temp; // Insert as right child
                              break;
                         }
                         else
                         {
                              ptr = ptr->rchild; // Move to right child
                         }
                    }
               }
          }
          printf("\nDo you want to add more nodes (Y/N): ");
          ch = getche(); // Get user choice
     } while (ch == 'Y' || ch == 'y');

     return root; // Return the root
}

// Insert a node into a BST
node *insert(node *root, node *temp)
{
     node *ptr;

     if (root == NULL)
     {
          root = temp; // Set as root if tree is empty
     }
     else
     {
          ptr = root;
          while (ptr != NULL)
          {
               if (temp->data < ptr->data)
               {
                    if (ptr->lchild == NULL)
                    {
                         ptr->lchild = temp; // Insert as left child
                         break;
                    }
                    else
                    {
                         ptr = ptr->lchild; // Move to left child
                    }
               }
               else
               {
                    if (ptr->rchild == NULL)
                    {
                         ptr->rchild = temp; // Insert as right child
                         break;
                    }
                    else
                    {
                         ptr = ptr->rchild; // Move to right child
                    }
               }
          }
     }

     return root; // Return the root
}

// Display the BST
void display(node *ptr)
{
     if (ptr != NULL)
     {
          display(ptr->lchild);     // Display left subtree
          printf(" %d", ptr->data); // Display node data
          display(ptr->rchild);     // Display right subtree
     }
}

// Main function
void main()
{
     int ch;
     node *root = NULL, *temp;

     clrscr(); // Clear the screen
     while (1)
     {
          printf("\n1: Create a BST.");
          printf("\n2: Insert element into a BST.");
          printf("\n3: Display");
          printf("\n4: Exit");
          printf("\nEnter the Choice: ");
          scanf("%d", &ch); // Get user choice
          switch (ch)
          {
          case 1:
               root = create(); // Create a new BST
               break;
          case 2:
               temp = getnode();          // Create a new node
               root = insert(root, temp); // Insert the node
               break;
          case 3:
               display(root); // Display the BST
               break;
          case 4:
               exit(0); // Exit the program
          }
     }
}
