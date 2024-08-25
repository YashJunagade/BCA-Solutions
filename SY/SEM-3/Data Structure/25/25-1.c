#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define MAX 50

int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Array to keep track of visited nodes
int n;                   // Number of vertices

// Function to perform DFS traversal
void dfs(int v)
{
     int i;
     // Mark the current node as visited
     visited[v] = 1;
     printf("%d ", v);

     // Traverse all adjacent vertices
     for (i = 0; i < n; i++)
     {
          if (adjMatrix[v][i] && !visited[i])
          {
               dfs(i);
          }
     }
}

void main()
{
     int i, j, startVertex;

     clrscr(); // Clear the screen

     // Read the number of vertices
     printf("Enter the number of vertices: ");
     scanf("%d", &n);

     // Initialize the adjacency matrix
     printf("Enter the adjacency matrix (0s and 1s):\n");
     for (i = 0; i < n; i++)
     {
          for (j = 0; j < n; j++)
          {
               scanf("%d", &adjMatrix[i][j]);
          }
     }

     // Initialize visited array to 0
     for (i = 0; i < n; i++)
     {
          visited[i] = 0;
     }

     // Read the starting vertex for DFS
     printf("Enter the starting vertex for DFS: ");
     scanf("%d", &startVertex);

     // Perform DFS traversal
     printf("DFS Traversal starting from vertex %d:\n", startVertex);
     dfs(startVertex);

     getch(); // Wait for a key press
}
