#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 50
#define MAX_NAME_LENGTH 100

// Function to perform Bubble Sort on an array of strings
void bubbleSort(char names[][MAX_NAME_LENGTH], int n)
{
     int i, j;
     char temp[MAX_NAME_LENGTH];

     for (i = 0; i < n - 1; i++)
     {
          for (j = 0; j < n - i - 1; j++)
          {
               if (strcmp(names[j], names[j + 1]) > 0)
               {
                    // Swap names[j] and names[j+1]
                    strcpy(temp, names[j]);
                    strcpy(names[j], names[j + 1]);
                    strcpy(names[j + 1], temp);
               }
          }
     }
}

// Main function
void main()
{
     char names[MAX][MAX_NAME_LENGTH];
     int n, i;

     clrscr(); // Clear the screen

     printf("Enter the number of names: ");
     scanf("%d", &n);
     getchar(); // To consume the newline character left by scanf

     // Accept names from the user
     for (i = 0; i < n; i++)
     {
          printf("Enter name %d: ", i + 1);
          fgets(names[i], MAX_NAME_LENGTH, stdin);
          // Remove newline character from the end of the string
          names[i][strcspn(names[i], "\n")] = '\0';
     }

     // Sort names in alphabetical order
     bubbleSort(names, n);

     // Display sorted names
     printf("\nSorted names:\n");
     for (i = 0; i < n; i++)
     {
          printf("%s\n", names[i]);
     }

     getch(); // Wait for a key press
}
