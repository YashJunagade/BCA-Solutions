/*B) Write a ‘C’ program to accept the names of cities and store them in array. Accept
the city name from user and use linear search algorithm to check whether the city is
present in array or not. */

// #include <stdio.h>
// #include <string.h>

// int linearSearch(char c[10][20], int n, char key[])
// {
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         if (strcmp(c[i], key) == 0)
//             return i;
//     }
//     return -1;
// }

// int main()
// {
//     int i, n;
//     char city[10][20], key[20];
//     printf("Enter the Size :");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//     {
//         printf("Enter the %d City Name :", i + 1);
//         scanf("%s", &city[i]);
//     }
//     printf("Enter the City name you want to search :");
//     scanf("%s", &key);
//     n = linearSearch(city, n, key);
//     if (n != -1)
//         printf("%s is found at %d index ", key, n);
//     else
//         printf("%s is not found", key);
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void linearSearch(char c[20][20], int n, char key[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(c[i], key) == 0)
        {
            printf("%s is found at %d index", key, i + 1);
            exit(1);
        }
    }
    printf("%s is not found", key);
}

int main()
{
    char cities[20][20], key[20];
    int i, n;

    printf("Enter the size of array :");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the %d city name :", i + 1);
        scanf("%s", &cities[i]);
    }

    printf("Enter the City you want to find :");
    scanf("%s", &key);

    linearSearch(cities, n, key);
    return 0;
}