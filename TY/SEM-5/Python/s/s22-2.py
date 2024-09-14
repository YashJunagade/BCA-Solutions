def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        # Track if any swaps were made in this pass
        swapped = False
        # Perform the bubble sort pass
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap if elements are in the wrong order
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # If no elements were swapped, the list is sorted
        if not swapped:
            break

# Example usage
arr = [64, 34, 25, 12, 22, 11, 90]
print("Original list:", arr)
bubble_sort(arr)
print("Sorted list:", arr)
