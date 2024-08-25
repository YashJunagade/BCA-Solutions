#include <stdio.h>
#include <conio.h>

void insertionSort(int arr[], int n)
{
     int i, key, j;
     for (i = 1; i < n; i++)
     {
          key = arr[i];
          j = i - 1;

          // Move elements of arr[0..i-1], that are greater than key,
          // to one position ahead of their current position
          while (j >= 0 && arr[j] > key)
          {
               arr[j + 1] = arr[j];
               j = j - 1;
          }
          arr[j + 1] = key;
     }
}

void main()
{
     int n, i;

     clrscr(); // Clear the screen

     printf("Enter the number of elements: ");
     scanf("%d", &n);

     int arr[n];

     printf("Enter %d elements:\n", n);
     for (i = 0; i < n; i++)
     {
          printf("Element %d: ", i + 1);
          scanf("%d", &arr[i]);
     }

     insertionSort(arr, n);

     printf("Sorted array in ascending order:\n");
     for (i = 0; i < n; i++)
     {
          printf("%d ", arr[i]);
     }
     printf("\n");

     getch(); // Wait for a key press
}
