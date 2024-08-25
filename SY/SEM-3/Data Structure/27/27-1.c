#include <stdio.h>
#define MAX 5 // Define the size of the queue

typedef struct
{
     int front, rear, size;
     int queue[MAX];
} CircularQueue;

// Function to initialize the queue
void Initialize(CircularQueue *cq)
{
     cq->front = cq->rear = -1;
     cq->size = 0;
}

// Function to check if the queue is empty
int isempty(CircularQueue *cq)
{
     return cq->size == 0;
}

// Function to check if the queue is full
int isfull(CircularQueue *cq)
{
     return cq->size == MAX;
}

// Function to insert an element into the queue
void insert(CircularQueue *cq, int value)
{
     if (isfull(cq))
     {
          printf("Queue is full!\n");
          return;
     }
     if (isempty(cq))
     {
          cq->front = 0;
     }
     cq->rear = (cq->rear + 1) % MAX;
     cq->queue[cq->rear] = value;
     cq->size++;
}

// Function to delete an element from the queue
void delete(CircularQueue *cq)
{
     if (isempty(cq))
     {
          printf("Queue is empty!\n");
          return;
     }
     printf("Deleted element: %d\n", cq->queue[cq->front]);
     cq->front = (cq->front + 1) % MAX;
     cq->size--;
}

// Function to display the elements of the queue
void display(CircularQueue *cq)
{
     if (isempty(cq))
     {
          printf("Queue is empty!\n");
          return;
     }
     printf("Queue elements: ");
     int i;
     for (i = 0; i < cq->size; i++)
     {
          printf("%d ", cq->queue[(cq->front + i) % MAX]);
     }
     printf("\n");
}

int main()
{
     CircularQueue cq;
     int choice, value;

     clrscr(); // Clear the screen (Turbo C specific)
     Initialize(&cq);

     while (1)
     {
          printf("\nCircular Queue Operations:\n");
          printf("1. Insert\n");
          printf("2. Delete\n");
          printf("3. Display\n");
          printf("4. Exit\n");
          printf("Enter your choice: ");
          scanf("%d", &choice);

          switch (choice)
          {
          case 1:
               printf("Enter value to insert: ");
               scanf("%d", &value);
               insert(&cq, value);
               break;
          case 2:
               delete (&cq);
               break;
          case 3:
               display(&cq);
               break;
          case 4:
               return 0;
          default:
               printf("Invalid choice!\n");
          }
     }
     getch(); // Wait for user input before closing (Turbo C specific)
     return 0;
}
