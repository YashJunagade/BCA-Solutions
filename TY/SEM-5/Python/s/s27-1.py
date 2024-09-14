def unzip_tuples(list_of_tuples):
    # Use zip with unpacking to unzip the list of tuples
    return list(zip(*list_of_tuples))

# Example usage
list_of_tuples = [(1, 'a', 3.5), (2, 'b', 4.6), (3, 'c', 5.7)]
unzipped = unzip_tuples(list_of_tuples)

# Convert the result to individual lists
list1, list2, list3 = unzipped

print("List 1:", list(list1))
print("List 2:", list(list2))
print("List 3:", list(list3))
