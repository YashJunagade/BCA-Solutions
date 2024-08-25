#include <stdio.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time() to seed the random number generator

#define MAX 100 // Maximum size of the array

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int n)
{
     int i, j, temp;
     for (i = 0; i < n - 1; i++)
     {
          for (j = 0; j < n - i - 1; j++)
          {
               if (arr[j] > arr[j + 1])
               {
                    // Swap arr[j] and arr[j + 1]
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
               }
          }
     }
}

// Function to perform binary search
int binarySearch(int arr[], int n, int x)
{
     int low = 0, high = n - 1, mid;
     while (low <= high)
     {
          mid = (low + high) / 2;
          if (arr[mid] == x)
          {
               return mid; // Element found
          }
          else if (arr[mid] < x)
          {
               low = mid + 1;
          }
          else
          {
               high = mid - 1;
          }
     }
     return -1; // Element not found
}

// Main function
int main()
{
     int n, arr[MAX], i, x, index;

     clrscr(); // Clear the screen (Turbo C specific)

     // Seed the random number generator
     srand(time(0));

     // Accept the size of the array
     printf("Enter the number of elements in the array: ");
     scanf("%d", &n);

     // Generate random numbers and store them in the array
     printf("Generated array:\n");
     for (i = 0; i < n; i++)
     {
          arr[i] = rand() % 100; // Generate random numbers between 0 and 99
          printf("%d\t", arr[i]);
     }
     printf("\n");

     // Sort the array using Bubble Sort
     bubbleSort(arr, n);

     // Display the sorted array
     printf("Sorted array:\n");
     for (i = 0; i < n; i++)
     {
          printf("%d\t", arr[i]);
     }
     printf("\n");

     // Accept the value to search for
     printf("Enter the value to search for: ");
     scanf("%d", &x);

     // Perform binary search
     index = binarySearch(arr, n, x);

     // Display the result
     if (index != -1)
     {
          printf("Value %d found at index %d.\n", x, index);
     }
     else
     {
          printf("Value %d not found in the array.\n", x);
     }

     getch(); // Wait for user input before closing (Turbo C specific)
     return 0;
}
