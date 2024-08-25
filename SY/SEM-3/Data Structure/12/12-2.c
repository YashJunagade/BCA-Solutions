#include <stdio.h>
#include <conio.h>

#define MAX 100

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
     int i, j, minIndex, temp;

     for (i = 0; i < n - 1; i++)
     {
          // Find the minimum element in unsorted part of array
          minIndex = i;
          for (j = i + 1; j < n; j++)
          {
               if (arr[j] < arr[minIndex])
               {
                    minIndex = j;
               }
          }

          // Swap the found minimum element with the first element of the unsorted part
          if (minIndex != i)
          {
               temp = arr[i];
               arr[i] = arr[minIndex];
               arr[minIndex] = temp;
          }
     }
}

// Main function
void main()
{
     int arr[MAX];
     int n, i;

     clrscr(); // Clear the screen

     printf("Enter the number of elements: ");
     scanf("%d", &n);

     printf("Enter %d elements:\n", n);
     for (i = 0; i < n; i++)
     {
          printf("Element %d: ", i + 1);
          scanf("%d", &arr[i]);
     }

     // Call selection sort
     selectionSort(arr, n);

     // Display the sorted array
     printf("\nSorted array in ascending order:\n");
     for (i = 0; i < n; i++)
     {
          printf("%d ", arr[i]);
     }

     getch(); // Wait for a key press
}
