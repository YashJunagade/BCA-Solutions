# Create a sample matrix
matrix_data <- matrix(1:9, nrow = 3)

# Convert the matrix to a list
list_data <- as.list(matrix_data)

# Print the list in ascending order
sorted_list_data <- sort(unlist(list_data))
print(sorted_list_data)
