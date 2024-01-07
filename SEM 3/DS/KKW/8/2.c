/*B) Write a ‘C’ program to accept and sort n elements in ascending order by using
insertion sort.
*/

#include <stdio.h>

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

    insertionSort(a, n);
    printf("\nSortd Array :\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    return 0;
}