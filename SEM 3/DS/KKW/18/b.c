/*B) Write a ‘C’ program to accept and sort n elements in ascending order using Merge
sort method. */

// #include <stdio.h>

// void merge(int a[], int l, int mid, int h)
// {
//     int i = l, j = mid + 1, k = l;
//     int b[10];

//     while (i <= mid && j <= h)
//     {
//         if (a[i] <= a[j])
//         {
//             b[k] = a[i];
//             i++;
//         }
//         else
//         {
//             b[k] = a[j];
//             j++;
//         }
//         k++;
//     }

//     while (i <= mid)
//     {
//         b[k] = a[i];
//         i++;
//         k++;
//     }

//     while (j <= h)
//     {
//         b[k] = a[j];
//         j++;
//         k++;
//     }

//     for (i = l; i <= h; i++)
//     {
//         a[i] = b[i];
//     }
// }

// void mergeSort(int a[], int l, int h)
// {
//     if (l < h)
//     {
//         int mid = (l + h) / 2;
//         mergeSort(a, l, mid);
//         mergeSort(a, mid + 1, h);
//         merge(a, l, mid, h);
//     }
// }

// int main()
// {
//     int a[10], i, n;
//     printf("Enter the size of the array: ");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//     {
//         printf("Enter element %d: ", i + 1);
//         scanf("%d", &a[i]);
//     }

//     printf("Original Array:\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);

//     mergeSort(a, 0, n - 1);

//     printf("\nSorted Array:\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t", a[i]);

//     return 0;
// }

#include <stdio.h>

void merge(int a[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l, b[20];

    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= h)
        b[k++] = a[j++];

    for (i = l; i <= h; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

int main()
{
    int n, a[20], i;
    printf("Enter the size of array :");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the %d element :", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Original Array :\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    mergeSort(a, 0, n - 1);
    printf("\nSorted Array :\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}