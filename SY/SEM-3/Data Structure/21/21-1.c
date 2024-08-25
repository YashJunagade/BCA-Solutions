#include <stdio.h>
#include <conio.h>

#define MAX 10 // Maximum number of vertices in the graph

// Function to perform BFS traversal
void bfs(int graph[MAX][MAX], int visited[MAX], int n, int start)
{
     int queue[MAX], front = 0, rear = 0;
     int i;

     // Mark the start node as visited and enqueue it
     visited[start] = 1;
     queue[rear++] = start;

     printf("BFS Traversal starting from node %d:\n", start);

     while (front < rear)
     {
          int node = queue[front++]; // Dequeue a node

          printf("%d ", node);

          // Process all adjacent nodes
          for (i = 0; i < n; i++)
          {
               if (graph[node][i] && !visited[i])
               {
                    visited[i] = 1;    // Mark as visited
                    queue[rear++] = i; // Enqueue the node
               }
          }
     }
     printf("\n");
}

int main()
{
     int graph[MAX][MAX], visited[MAX], n, i, j, start;

     clrscr(); // Clear the screen (Turbo C specific)

     // Initialize visited array to 0
     for (i = 0; i < MAX; i++)
     {
          visited[i] = 0;
     }

     // Read the number of vertices
     printf("Enter the number of vertices (max %d): ", MAX);
     scanf("%d", &n);

     // Read the adjacency matrix
     printf("Enter the adjacency matrix:\n");
     for (i = 0; i < n; i++)
     {
          for (j = 0; j < n; j++)
          {
               scanf("%d", &graph[i][j]);
          }
     }

     // Read the starting node for BFS
     printf("Enter the starting node for BFS: ");
     scanf("%d", &start);

     // Perform BFS traversal
     bfs(graph, visited, n, start);

     getch(); // Wait for user input before closing (Turbo C specific)
     return 0;
}
