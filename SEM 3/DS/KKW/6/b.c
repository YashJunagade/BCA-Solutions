/*B) Write a ‘C’ program to accept and sort n elements in ascending order by using
bubble sort*/

// #include <stdio.h>

// void bubbleSort(int a[], int n)
// {
//     int i, j, temp, swapped = 0;
//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = 0; j < n - i - 1; j++)
//         {
//             if (a[j] > a[j + 1])
//             {
//                 temp = a[j + 1];
//                 a[j + 1] = a[j];
//                 a[j] = temp;
//                 swapped = 1;
//             }
//         }
//         if (swapped == 0)
//             break;
//     }
// }

// int main()
// {
//     int i, a[20], n;
//     printf("Enter the size of array :");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//     {
//         printf("Enter the %d element :", i + 1);
//         scanf("%d", &a[i]);
//     }

//     printf("Original Array :\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);

//     bubbleSort(a, n);
//     printf("\nSorted Array :\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);
// }

// #include <stdio.h>

// void bubbleSort(int a[], int n)
// {
//     int i, j, temp, swapped = 0;

//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = 0; j < n - i - 1; j++)
//         {
//             if (a[j] > a[j + 1])
//             {
//                 temp = a[j + 1];
//                 a[j + 1] = a[j];
//                 a[j] = temp;
//                 swapped = 1;
//             }
//         }
//         if (swapped == 0)
//             break;
//     }
// }

// int main()
// {
//     int n, a[10], i;
//     printf("Enter size of array :");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//     {
//         printf("Enter %d element :", i + 1);
//         scanf("%d", &a[i]);
//     }

//     printf("Original Array :\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);

//     bubbleSort(a, n);
//     printf("\nSorted Array :\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);
// }

#include <stdio.h>

void insertionSort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
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
    int n, a[10], i;
    printf("Enter the size of array :");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter %d element :", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Original Array :\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    insertionSort(a, n);
    printf("\nSorted Array :\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}