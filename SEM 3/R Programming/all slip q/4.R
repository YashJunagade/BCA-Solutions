# Define the input string
input_string <- "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

# Extract the first 10 English letters in lower case
ans1 <- substr(input_string, 1, 10)

# Extract the last 10 letters in upper case
ans2 <- substr(input_string, nchar(input_string) - 9, nchar(input_string))

# Extract letters between 22nd to 24th letters in upper case
ans3 <- substr(input_string, 22, 24)

# Print the results
cat("First 10 English letters in lower case:", ans1, "\n")
cat("Last 10 letters in upper case:", ans2, "\n")
cat("Letters between 22nd to 24th in upper case:", ans3, "\n")
