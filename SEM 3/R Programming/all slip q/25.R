# Create a list with vectors, matrices, and a function
my_list <- list(
  vector = c(1, 2, 3),
  matrix = matrix(1:6, nrow = 2),
  Myfunction = function(x) x * 2
)

# Print the content of the list
cat("List Contents:\n")
print(my_list)
