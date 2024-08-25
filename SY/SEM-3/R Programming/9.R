# Create a factor with some levels
my_factor <- factor(c("A", "B", "C", "A", "B", "C"))

# Display the original factor
cat("Original Factor:\n")
print(my_factor)

# Change the first level to "X"
levels(my_factor)[1] <- "X"

# Display the modified factor
cat("\nModified Factor:\n")
print(my_factor)
