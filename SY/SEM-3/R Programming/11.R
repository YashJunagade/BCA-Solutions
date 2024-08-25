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

# Perform addition and subtraction of arrays
addition_result <- array1 + array2
subtraction_result <- array1 - array2

# Print the results
cat("Vector 1:\n")
print(array1)

cat("\nVector 2:\n")
print(array2)

cat("\nAddition Result:\n")
print(addition_result)

cat("\nSubtraction Result:\n")
print(subtraction_result)
