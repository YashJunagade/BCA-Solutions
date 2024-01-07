# Create a factor with some levels
myFact <- factor(c("A", "B", "C", "A", "B", "C"))

# Display the original factor
cat("Original Factor:\n")
print(myFact)

# Change the first level to "X"
levels(myFact)[1] <- "X"

# Display the modified factor
cat("\nModified Factor:\n")
print(myFact)
