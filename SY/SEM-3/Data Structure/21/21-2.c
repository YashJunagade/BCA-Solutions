#include <stdio.h>
#include <conio.h> // For Turbo C's clrscr() and getch()

// Function to perform linear search
int linearSearch(int arr[], int n, int value)
{
     int i;
     for (i = 0; i < n; i++)
     {
          if (arr[i] == value)
          {
               return i; // Return index if value is found
          }
     }
     return -1; // Return -1 if value is not found
}

int main()
{
     int n, i, value, result;
     int arr[100]; // Array to store elements

     clrscr(); // Clear the screen (Turbo C specific)

     // Read the number of elements
     printf("Enter the number of elements (max 100): ");
     scanf("%d", &n);

     // Check if the number of elements is within the allowed range
     if (n > 100 || n <= 0)
     {
          printf("Invalid number of elements.\n");
          getch();  // Wait for user input before closing (Turbo C specific)
          return 1; // Exit the program with an error code
     }

     // Read the elements of the array
     printf("Enter %d elements:\n", n);
     for (i = 0; i < n; i++)
     {
          printf("Element %d: ", i + 1);
          scanf("%d", &arr[i]);
     }

     // Read the value to search for
     printf("Enter the value to search for: ");
     scanf("%d", &value);

     // Perform linear search
     result = linearSearch(arr, n, value);

     // Display the result
     if (result != -1)
     {
          printf("Value %d found at index %d.\n", value, result);
     }
     else
     {
          printf("Value %d not found in the array.\n", value);
     }

     getch(); // Wait for user input before closing (Turbo C specific)
     return 0;
}
