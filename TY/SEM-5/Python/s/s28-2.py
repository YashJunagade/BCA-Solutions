def merge_lists_to_tuples(list1, list2):
    # Merge the two lists into a list of tuples
    return list(zip(list1, list2))

# Example usage
list1 = input("Enter the first list of elements separated by spaces: ").split()
list2 = input("Enter the second list of elements separated by spaces: ").split()

# Convert the input lists to tuples
merged_list = merge_lists_to_tuples(list1, list2)

print("Merged list of tuples:", merged_list)
