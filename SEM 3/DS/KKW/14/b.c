/*B)Write a ‘C’ program to accept names from the user and sort in alphabetical order
using bubble sort
- Accept n name
- Bubble sort Function
- Display
*/

// #include <stdio.h>
// #include <string.h>

// void bubbleSort(char a[10][20], int n)
// {
//     int i, j;
//     char temp[20];

//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = 0; j < n - i - 1; j++)
//         {
//             if (strcmp(a[j + 1], a[j]) < 0)
//             {
//                 strcpy(temp, a[j]);
//                 strcpy(a[j], a[j + 1]);
//                 strcpy(a[j + 1], temp);
//             }
//         }
//     }
// }

// int main()
// {
//     int i, n;
//     char a[10][20];

//     printf("Enter the size of array :");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//     {
//         printf("Enter the %d name :", i + 1);
//         scanf("%s", a[i]);
//     }

//     printf("Orginal Array :\n");
//     for (i = 0; i < n; i++)
//         printf("%s\t", a[i]);

//     bubbleSort(a, n);
//     printf("\nSorted Array :\n");
//     for (i = 0; i < n; i++)
//         printf("%s\t", a[i]);

//     return 0;
// }

#include <stdio.h>
#include <string.h>

void bubbleSort(char names[20][20], int n)
{
    int i, j;
    char temp[20];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(names[j + 1], names[j]) < 0)
            {
                strcpy(temp, names[j + 1]);
                strcpy(names[j + 1], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

int main()
{
    char names[20][20];
    int n, i;

    printf("Enter the size of array :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the %d name :", i + 1);
        scanf("%s", &names[i]);
    }

    printf("Original Names :");
    for (i = 0; i < n; i++)
        printf("%s\t", names[i]);

    bubbleSort(names, n);
    printf("\nSorted Names :");
    for (i = 0; i < n; i++)
        printf("%s\t", names[i]);
    return 0;
}