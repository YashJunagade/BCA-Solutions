#include <stdio.h>

#define MAX 20 // Define a maximum size for the array

// Function to merge two halves of the array
void merge(int a[], int l, int mid, int h)
{
     int i = l, j = mid + 1, k = l;
     int b[MAX]; // Temporary array to store merged result

     // Merge the two halves into the temporary array
     while (i <= mid && j <= h)
     {
          if (a[i] <= a[j])
          {
               b[k++] = a[i++];
          }
          else
          {
               b[k++] = a[j++];
          }
     }

     // Copy remaining elements of the left half, if any
     while (i <= mid)
     {
          b[k++] = a[i++];
     }

     // Copy remaining elements of the right half, if any
     while (j <= h)
     {
          b[k++] = a[j++];
     }

     // Copy the merged elements back to the original array
     for (i = l; i <= h; i++)
     {
          a[i] = b[i];
     }
}

// Function to perform merge sort
void mergeSort(int a[], int l, int h)
{
     if (l < h)
     {
          int mid = (l + h) / 2;    // Find the middle point
          mergeSort(a, l, mid);     // Sort the first half
          mergeSort(a, mid + 1, h); // Sort the second half
          merge(a, l, mid, h);      // Merge the sorted halves
     }
}

int main()
{
     int n, a[MAX], i;

     // Get the size of the array from the user
     printf("Enter the size of the array (max %d): ", MAX);
     scanf("%d", &n);

     if (n > MAX)
     {
          printf("Size exceeds the maximum limit of %d\n", MAX);
          return 1; // Exit with error code
     }

     // Input array elements
     for (i = 0; i < n; i++)
     {
          printf("Enter element %d: ", i + 1);
          scanf("%d", &a[i]);
     }

     // Display original array
     printf("Original Array:\n");
     for (i = 0; i < n; i++)
     {
          printf("%d\t", a[i]);
     }
     printf("\n");

     // Sort the array using merge sort
     mergeSort(a, 0, n - 1);

     // Display sorted array
     printf("Sorted Array:\n");
     for (i = 0; i < n; i++)
     {
          printf("%d\t", a[i]);
     }
     printf("\n");

     return 0;
}
