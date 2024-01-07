# Create two vectors
vector1 <- c("Deva", "Mayra", "shreya", "Aditi")
vector2 <- c(18, 28, 32, 25)

# Create a data frame using the vectors
my_data_frame <- data.frame(Name = vector1, Age = vector2)

# Display duplicated elements
duplicated_elements <- my_data_frame[duplicated(my_data_frame), ]

# Display unique rows
unique_rows <- my_data_frame[!duplicated(my_data_frame), ]

# Print the results
cat("Duplicated Elements:\n")
print(duplicated_elements)

cat("\nUnique Rows:\n")
print(unique_rows)
