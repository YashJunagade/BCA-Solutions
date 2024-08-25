# Create a factor from a random sample of LETTERS
set.seed(123)  # For reproducibility
random_factor <- factor(sample(LETTERS, 20, replace = TRUE))

# Extract five levels from the factor
sampled_levels <- levels(random_factor)[sample(length(levels(random_factor)), 5)]

# Print the sampled levels
cat("Sampled Levels:\n")
print(sampled_levels)
