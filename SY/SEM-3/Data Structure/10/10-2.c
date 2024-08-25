#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Function to perform insertion sort
void insertionSort(int arr[], int n)
{
     int i, j, key;
     for (i = 1; i < n; i++)
     {
          key = arr[i];
          j = i - 1;

          // Move elements of arr[0..i-1] that are greater than key
          // to one position ahead of their current position
          while (j >= 0 && arr[j] > key)
          {
               arr[j + 1] = arr[j];
               j = j - 1;
          }
          arr[j + 1] = key;
     }
}

// Function to print the array
void printArray(int arr[], int n)
{
     int i;
     for (i = 0; i < n; i++)
     {
          printf("%d ", arr[i]);
     }
     printf("\n");
}

// Main function
void main()
{
     int arr[MAX];
     int n, i;

     clrscr(); // Clear the screen

     // Seed the random number generator
     srand(time(0));

     printf("Enter the number of elements: ");
     scanf("%d", &n);

     // Generate random numbers and store them in the array
     for (i = 0; i < n; i++)
     {
          arr[i] = rand() % 100; // Generate random number between 0 and 99
     }

     printf("Original array:\n");
     printArray(arr, n);

     // Sort the array using insertion sort
     insertionSort(arr, n);

     printf("Sorted array:\n");
     printArray(arr, n);

     getch(); // Wait for a key press
}
