# Function to calculate binary representation
decimalToBinary <- function(decimal) {
  binary <- intToBits(decimal)
  binary <- as.character(binary)
  binary <- substr(binary, nchar(binary) - 31, nchar(binary))
  return(binary)
}

# Input: Decimal number
decimal <- 42  # Change this to the desired decimal number

# Calculate binary representation
binary <- decimalToBinary(decimal)

# Print the binary representation
cat("Decimal:", decimal, "\n")
cat("Binary:", binary, "\n")
