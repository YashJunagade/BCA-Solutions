# Create two vectors of different lengths
vector1 <- c(1, 2, 3)
vector2 <- c(4, 5, 6, 7)

# Determine the common length (minimum length)
common_length <- min(length(vector1), length(vector2))

# Extract the common length from both vectors
vector1 <- vector1[1:common_length]
vector2 <- vector2[1:common_length]

# Convert vectors to arrays
array1 <- array(vector1, dim = c(common_length, 1))
array2 <- array(vector2, dim = c(common_length, 1))

# Combine the arrays into an array
combined_array <- array(c(array1, array2), dim = c(common_length, 2))

# Print the second row of the second matrix
cat("Second Row of the Second Matrix:\n")
print(combined_array[2, 2])
