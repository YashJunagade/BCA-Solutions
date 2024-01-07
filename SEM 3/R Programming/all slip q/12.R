# Function to calculate and print a multiplication table
calculateMultiplicationTable <- function(number) {
  for (i in 1:10) {
    result <- number * i
    cat(number, "x", i, "=", result, "\n")
  }
}

# Specify the number and range
number <- 5  # Change this to the desired number

# Call the function to calculate and print the multiplication table
calculateMultiplicationTable(number)
