# Create two factors
factor1 <- factor(c("A", "B", "C"))
factor2 <- factor(c("D", "E", "F"))

# Concatenate the factors
factors <- factor(c(factor1, factor2))

# Display the concatenated factor in descending order
sorted_factor <- factor(factors, levels = rev(levels(concatenated_factor)))
print(sorted_factor)



fact1 = factor(c(1, 2, 3, 4))
fact2 = factor(c(5, 6, 7, 8))

fact = factor(c(fact1, fact2))
desc = factor(fact, rev(fact))
print(desc)