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

# Calculate the multiplication of matrices
multiplication_result <- array1 %*% t(array2)

# Print the multiplication result
cat("Multiplication Result:\n")
print(multiplication_result)


# Create two vectors of different lengths
vector1 <- c(1, 2, 3)
vector2 <- c(4, 5)

# Create matrices from the vectors
mat1 <- matrix(vector1, nrow = 1)
mat2 <- matrix(vector2, nrow = 1)

# Multiply the matrices
result <- mat1 %*% t(mat2)

# Print the multiplication result
print("Multiplication result:")
print(result)


vect1 = c(1, 2, 3, 4, 5, 6)
vect2 = c(7, 8, 9, 10, 11, 12, 13, 14)

arr1 = matrix(vect1, nrow=2, ncol=3)
arr2 = matrix(vect2, nrow=3, ncol=3)
print(arr1)
print(arr2)

mul = arr1 %*% arr2

print(mul)