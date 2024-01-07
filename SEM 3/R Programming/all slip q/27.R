# Input binary number as a character string
binary <- "1101"  # Replace this with the binary number you want to convert

# Convert binary to decimal
decimal <- as.integer(binary, base = 2)

# Print the decimal number
cat("Binary:", binary, "\n")
cat("Decimal:", decimal, "\n")
