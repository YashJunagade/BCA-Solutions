#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Include this header for clrscr()

#define MAX 5 // Define the maximum size of the queue

// Define the structure for the circular queue
struct CircularQueue
{
     int front, rear, size, capacity;
     int *array;
};

// Function to initialize the circular queue
void initialize(struct CircularQueue *queue, int capacity)
{
     queue->capacity = capacity;
     queue->front = 0;
     queue->rear = -1;
     queue->size = 0;
     queue->array = (int *)malloc(capacity * sizeof(int));
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue *queue)
{
     return (queue->size == 0);
}

// Function to check if the queue is full
int isFull(struct CircularQueue *queue)
{
     return (queue->size == queue->capacity);
}

// Function to insert an element into the queue
void insert(struct CircularQueue *queue, int item)
{
     if (isFull(queue))
     {
          printf("Queue is full. Cannot insert %d\n", item);
          return;
     }
     queue->rear = (queue->rear + 1) % queue->capacity;
     queue->array[queue->rear] = item;
     queue->size++;
     printf("%d inserted into the queue.\n", item);
}

// Function to delete an element from the queue
void delete(struct CircularQueue *queue)
{
     if (isEmpty(queue))
     {
          printf("Queue is empty. Nothing to delete.\n");
          return;
     }
     int item = queue->array[queue->front];
     queue->front = (queue->front + 1) % queue->capacity;
     queue->size--;
     printf("%d deleted from the queue.\n", item);
}

// Function to display the elements of the queue
void display(struct CircularQueue *queue)
{
     if (isEmpty(queue))
     {
          printf("Queue is empty.\n");
          return;
     }
     printf("Queue elements: ");
     for (int i = 0; i < queue->size; i++)
     {
          int index = (queue->front + i) % queue->capacity;
          printf("%d ", queue->array[index]);
     }
     printf("\n");
}

// Main function
int main()
{
     struct CircularQueue queue;

     initialize(&queue, MAX); // Initialize the queue with a capacity of MAX

     clrscr(); // Clear the screen

     insert(&queue, 10);
     insert(&queue, 20);
     insert(&queue, 30);
     insert(&queue, 40);
     insert(&queue, 50);

     clrscr(); // Clear the screen before displaying

     display(&queue);

     delete (&queue);
     delete (&queue);

     clrscr(); // Clear the screen before displaying again

     display(&queue);

     insert(&queue, 60);
     insert(&queue, 70);

     clrscr(); // Clear the screen before displaying the final state

     display(&queue);

     free(queue.array); // Free the allocated memory for the queue

     getch(); // Wait for a key press to close the console window

     return 0;
}
