// /*B) Write a ‘C’ program to sort randomly generated array elements using Insertion sort
// method. (Use Random Function)
// */

// #include <stdio.h>
// #include <stdlib.h>

// void insertionSort(int a[], int n)
// {
//     int i, j, temp;
//     for (i = 1; i < n; i++)
//     {
//         temp = a[i];
//         j = i - 1;

//         while (j >= 0 && temp < a[j])
//         {
//             a[j + 1] = a[j];
//             j--;
//         }
//         a[j + 1] = temp;
//     }
// }

// int main()
// {
//     int a[20], n, i;
//     printf("Enter the size of array :");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//         a[i] = rand() % 100;

//     printf("Original Array :\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);

//     // Insertion Sort Algorithm
//     insertionSort(a, n);
//     printf("\nSorted Array :\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// void insertionSort(int a[], int n)
// {
//     int i, j, temp;
//     for (i = 1; i < n; i++)
//     {
//         j = i - 1;
//         temp = a[i];
//         while (j >= 0 && temp < a[j])
//         {
//             a[j + 1] = a[j];
//             j--;
//         }
//         a[j + 1] = temp;
//     }
// }

// int main()
// {
//     int a[10], n, i;
//     printf("Enter the size of array :");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//         a[i] = rand() % 100;

//     printf("Original Array :\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);

//     insertionSort(a, n);
//     printf("\nSorted Array :\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int main()
{
    int a[10], n, i;
    printf("Enter the size of array :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        a[i] = rand() % 100;

    printf("Original Array :\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    insertionSort(a, n);
    printf("\nSorted Array :\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    return 0;
}