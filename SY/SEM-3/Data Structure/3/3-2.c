#include <stdio.h>
#include <conio.h>
#include <malloc.h> // For malloc function

#define MAX_VERTICES 20 // Maximum number of vertices

// Define the structure for an adjacency list node
struct AdjListNode
{
     int dest;
     struct AdjListNode *next;
};

typedef struct AdjListNode AdjListNode;

// Define the structure for an adjacency list
struct AdjList
{
     AdjListNode *head;
};

typedef struct AdjList AdjList;

// Define the graph structure
struct Graph
{
     int numVertices;
     AdjList *array;
};

typedef struct Graph Graph;

// Function to create a new adjacency list node
AdjListNode *createNode(int dest)
{
     AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
     newNode->dest = dest;
     newNode->next = NULL;
     return newNode;
}

// Function to create a graph with a given number of vertices
Graph *createGraph(int vertices)
{
     Graph *graph = (Graph *)malloc(sizeof(Graph));
     graph->numVertices = vertices;

     // Create an array of adjacency lists
     graph->array = (AdjList *)malloc(vertices * sizeof(AdjList));

     // Initialize each adjacency list as empty
     int i;
     for (i = 0; i < vertices; ++i)
          graph->array[i].head = NULL;

     return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest)
{
     // Add an edge from src to dest
     AdjListNode *newNode = createNode(dest);
     newNode->next = graph->array[src].head;
     graph->array[src].head = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(Graph *graph)
{
     int v;
     for (v = 0; v < graph->numVertices; ++v)
     {
          AdjListNode *pCrawl = graph->array[v].head;
          printf("\nAdjacency list of vertex %d\n head", v);
          while (pCrawl)
          {
               printf(" -> %d", pCrawl->dest);
               pCrawl = pCrawl->next;
          }
          printf("\n");
     }
}

void main()
{
     int i, j, numVertices;
     int adjMatrix[MAX_VERTICES][MAX_VERTICES];
     Graph *graph;

     clrscr(); // Clear the screen

     printf("Enter the number of vertices in the graph: ");
     scanf("%d", &numVertices);

     printf("Enter the adjacency matrix:\n");
     for (i = 0; i < numVertices; i++)
     {
          for (j = 0; j < numVertices; j++)
          {
               scanf("%d", &adjMatrix[i][j]);
          }
     }

     // Create a graph
     graph = createGraph(numVertices);

     // Convert adjacency matrix to adjacency list
     for (i = 0; i < numVertices; i++)
     {
          for (j = 0; j < numVertices; j++)
          {
               if (adjMatrix[i][j] == 1)
               {
                    addEdge(graph, i, j);
               }
          }
     }

     // Print the adjacency list
     printGraph(graph);

     getch(); // Wait for a key press
}
