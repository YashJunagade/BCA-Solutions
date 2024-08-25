# Create two sample data frames
df1 <- data.frame(ID = c(1, 2, 3, 4, 5),
                  Name = c("Yash", "Deva", "Mayra", "Shreya", "Tony"))

df2 <- data.frame(ID = c(3, 4, 6, 7),
                  Name = c("Mayra", "Shreya", "Aditi", "Gorkha"))

# Find elements in df1 that are not in df2
elements <- df1[!(df1$ID %in% df2$ID), ]

# Print the result
print(elements)
