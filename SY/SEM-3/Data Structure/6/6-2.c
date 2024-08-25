#include <stdio.h>
#include <conio.h>

#define MAX 100 // Define maximum number of elements

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
     int i, j, temp;
     for (i = 0; i < n - 1; i++)
     {
          for (j = 0; j < n - i - 1; j++)
          {
               if (arr[j] > arr[j + 1])
               {
                    // Swap arr[j] and arr[j+1]
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
               }
          }
     }
}

// Function to print the array
void printArray(int arr[], int n)
{
     int i;
     printf("Sorted array: ");
     for (i = 0; i < n; i++)
          printf("%d ", arr[i]);
     printf("\n");
}

void main()
{
     int arr[MAX], n, i;

     clrscr(); // Clear the screen

     // Input number of elements
     printf("Enter the number of elements: ");
     scanf("%d", &n);

     // Input elements
     printf("Enter %d elements:\n", n);
     for (i = 0; i < n; i++)
     {
          printf("Element %d: ", i + 1);
          scanf("%d", &arr[i]);
     }

     // Perform bubble sort
     bubbleSort(arr, n);

     // Print the sorted array
     printArray(arr, n);

     getch(); // Wait for a key press
}
