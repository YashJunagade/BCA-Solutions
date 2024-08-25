# Create a list of 10 strings
string_list <- c("apple", "banana", "cherry", "date", "fig", "grape", "kiwi", "lemon", "orange", "pear")

# Sort in ascending order
sorted_asc <- sort(string_list)
cat("Ascending order:\n")
cat(sorted_asc, "\n")

# Sort in descending order
sorted_desc <- sort(string_list, decreasing = TRUE)
cat("\nDescending order:\n")
cat(sorted_desc, "\n")
