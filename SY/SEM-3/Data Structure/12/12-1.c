#include <stdio.h>
#include <conio.h>

#define MAX 10

// Function to check if the matrix is symmetric
int isSymmetric(int matrix[MAX][MAX], int n)
{
     int i, j;
     for (i = 0; i < n; i++)
     {
          for (j = 0; j < n; j++)
          {
               if (matrix[i][j] != matrix[j][i])
               {
                    return 0; // Matrix is not symmetric
               }
          }
     }
     return 1; // Matrix is symmetric
}

// Function to calculate the in-degree of each vertex
void calculateInDegrees(int matrix[MAX][MAX], int n)
{
     int i, j;
     printf("\nIn-degrees of all vertices:\n");
     for (i = 0; i < n; i++)
     {
          int inDegree = 0;
          for (j = 0; j < n; j++)
          {
               if (matrix[j][i] == 1)
               {
                    inDegree++;
               }
          }
          printf("Vertex %d: %d\n", i, inDegree);
     }
}

// Main function
void main()
{
     int matrix[MAX][MAX];
     int n, i, j;

     clrscr(); // Clear the screen

     printf("Enter the number of vertices: ");
     scanf("%d", &n);

     // Input adjacency matrix
     printf("Enter the adjacency matrix (%d x %d):\n", n, n);
     for (i = 0; i < n; i++)
     {
          for (j = 0; j < n; j++)
          {
               printf("Matrix[%d][%d]: ", i, j);
               scanf("%d", &matrix[i][j]);
          }
     }

     // Check if the matrix is symmetric
     if (isSymmetric(matrix, n))
     {
          printf("\nThe graph is undirected.\n");
     }
     else
     {
          printf("\nThe graph is directed.\n");
     }

     // Calculate in-degrees of all vertices
     calculateInDegrees(matrix, n);

     getch(); // Wait for a key press
}
