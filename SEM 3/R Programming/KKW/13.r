# Load the iris dataset
data(iris)

# i) Create a variable "y" and attach the output attribute
y <- iris$Species

    # ii) Create a barplot to breakdown the output attribute
    barplot(table(y), main = "Species Distribution", xlab = "Species", ylab = "Count", col = "lightblue")

# iii) Create a density plot matrix for each attribute by class value
par(mfrow = c(1, 1))  # Reset the layout
pairs(iris[, 1:4], pch = 19, col = as.integer(y), main = "Density Plot Matrix by Species")



# Load the iris dataset
data(iris)

# Create a barplot to break down the output attribute
barplot(table(iris$Species), main = "Species Distribution")

# Create a density plot matrix by class value
pairs(iris[, 1:4], pch = 19, col = iris$Species, main = "Density Plot Matrix by Species")
