# Create a vector of values
values <- c(1, 2, 3, 4, 5, 6)

# Create a vector of dimensions
dim_vector <- c(2, 3)

# Create an array with dimensions
my_array <- array(values, dim = dim_vector)

# Add names for dimensions
dimnames(my_array) <- list(Rows = NULL, Columns = NULL)

# Print the array
cat("Array with Names for Dimensions:\n")
print(my_array)
