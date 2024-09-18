# Given tuples
t1 = (1, 2, 3, 4)
t2 = (3, 5, 2, 1)
t3 = (2, 2, 3, 1)

# Compute element-wise sum
result = tuple(a + b + c for a, b, c in zip(t1, t2, t3))

# Output result
print("Element-wise sum:", result)
