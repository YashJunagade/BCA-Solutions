/*B) Write a ‘C’ program to create a random array of n integers. Accept a value x from
user and use Binary search algorithm to check whether the number is present in array
or not.
(Students can accept sorted array or can use any sorting method to sort the array)
*/

// #include <stdio.h>

// int binarySearch(int a[], int l, int h, int key)
// {
//     if (l < h)
//     {
//         int mid = (l + h) / 2;
//         if (a[mid] == key)
//             return mid;
//         else if (a[mid] > key)
//             return binarySearch(a, l, mid - 1, key);
//         else
//             return binarySearch(a, mid + 1, h, key);
//     }
//     return -1;
// }

// int main()
// {
//     int a[10], n, i, ans, key;
//     printf("Enter size of array :");
//     scanf("%d", &n);

//     printf("Enter the %d Sorted element :", n);
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }

//     printf("Enter the element you want to search :");
//     scanf("%d", &key);
//     ans = binarySearch(a, 0, n - 1, key);
//     if (ans != -1)
//         printf("%d is found", key);
//     else
//         printf("%d is not found", key);
// }

#include <stdio.h>

int binarySearch(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            return binarySearch(a, l, mid - 1, key);
        else
            return binarySearch(a, mid + 1, h, key);
    }
    return -1;
}

int main()
{
    int n, a[20], i, ans, key;
    printf("Enter the size of array :");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the %d element (sorted array):", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Enter the data you want to find :");
    scanf("%d", &key);

    ans = binarySearch(a, 0, n - 1, key);
    if (ans == -1)
        printf("%d is not found", key);
    else
        printf("%d is found at %d index", key, ans);
    return 0;
}