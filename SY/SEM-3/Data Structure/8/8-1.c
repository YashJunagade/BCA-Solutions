#include <stdio.h>
#include <conio.h>

struct NODE
{
     struct NODE *lchild; // Pointer to left child
     int data;            // Node data
     struct NODE *rchild; // Pointer to right child
};

typedef struct NODE node;

// Create a new node
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
     node *root, *temp, *ptr;
     root = NULL;
     do
     {
          temp = getnode(); // Create new node
          if (root == NULL)
               root = temp; // Set as root if tree is empty
          else
          {
               ptr = root;
               while (ptr != NULL)
               {
                    if (temp->data < ptr->data)
                    { // Insert in left subtree
                         if (ptr->lchild == NULL)
                         {
                              ptr->lchild = temp;
                              break;
                         }
                         else
                              ptr = ptr->lchild;
                    }
                    else
                    { // Insert in right subtree
                         if (ptr->rchild == NULL)
                         {
                              ptr->rchild = temp;
                              break;
                         }
                         else
                              ptr = ptr->rchild;
                    }
               }
          }
          printf("\nDo you want to add more node (Y/N): ");
          ch = getche(); // Read user choice
     } while (ch == 'Y' || ch == 'y');
     return root;
}

// Display BST in inorder (left-root-right) traversal
void display(node *ptr)
{
     if (ptr != NULL)
     {
          display(ptr->lchild);     // Visit left subtree
          printf(" %d", ptr->data); // Print node data
          display(ptr->rchild);     // Visit right subtree
     }
}

// Search for a value in BST
int search(node *ptr, int val)
{
     while (ptr != NULL)
     {
          if (ptr->data == val)
               return 1; // Value found
          if (val < ptr->data)
               ptr = ptr->lchild; // Search left subtree
          else
               ptr = ptr->rchild; // Search right subtree
     }
     return 0; // Value not found
}

void main()
{
     int ch, val, resp;
     node *root = NULL;
     clrscr(); // Clear screen
     while (1)
     {
          printf("\n1: Create a BST.");
          printf("\n2: Display");
          printf("\n3: Search");
          printf("\n4: Exit");
          printf("\nEnter the Choice: ");
          scanf("%d", &ch);
          switch (ch)
          {
          case 1:
               root = create(); // Create BST
               break;
          case 2:
               display(root); // Display BST
               break;
          case 3:
               printf("\nEnter the value to search: ");
               scanf("%d", &val);
               resp = search(root, val); // Search for value
               if (resp == 1)
                    printf("\nValue is found in Tree.");
               else
                    printf("\nValue not found in Tree.");
               break;
          case 4:
               exit(0); // Exit program
          }
     }
     getch(); // Wait for user input
}
