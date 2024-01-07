#include <stdio.h>

void bubbleSort(int a[], int n)
{
    int i, j, temp, swapped = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main()
{
    int a[10], i, n;
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

    bubbleSort(a, n);
    printf("\nSorted Array :\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}
