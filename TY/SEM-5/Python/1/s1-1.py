# Read input numbers
numbers = list(map(int, input("Enter numbers separated by spaces: ").split()))

# Remove duplicates
unique_numbers = list(set(numbers))

# Print result
print("List after removing duplicates:", unique_numbers)
