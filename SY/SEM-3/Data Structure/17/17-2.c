#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_CITIES 50
#define MAX_NAME_LENGTH 50

// Function to perform linear search
int linearSearch(char cities[][MAX_NAME_LENGTH], int n, char *searchCity)
{
     for (int i = 0; i < n; i++)
     {
          if (strcmp(cities[i], searchCity) == 0)
          {
               return i; // City found at index i
          }
     }
     return -1; // City not found
}

void main()
{
     char cities[MAX_CITIES][MAX_NAME_LENGTH]; // Array to store city names
     char searchCity[MAX_NAME_LENGTH];
     int n, index;

     clrscr(); // Clear the screen

     // Accept the number of cities
     printf("Enter the number of cities: ");
     scanf("%d", &n);
     getch(); // To consume the newline character left by scanf

     // Accept the names of cities
     for (int i = 0; i < n; i++)
     {
          printf("Enter city %d: ", i + 1);
          gets(cities[i]); // Read the city name
     }

     // Accept the city name to search
     printf("Enter the city name to search: ");
     gets(searchCity); // Read the city name to search

     // Perform linear search
     index = linearSearch(cities, n, searchCity);

     // Display the result
     if (index != -1)
     {
          printf("City '%s' found at position %d.\n", searchCity, index + 1);
     }
     else
     {
          printf("City '%s' not found.\n", searchCity);
     }

     getch(); // Wait for a key press before exiting
}
