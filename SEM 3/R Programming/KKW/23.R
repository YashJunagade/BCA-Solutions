# Create two vectors of different lengths
vec1 <- 1:5
vec2 <- 6:9

# Create an array from the vectors
arr <- array(c(vec1, vec2), dim = c(5, 2, 2))

# Print the second row of the second matrix
print(arr[2,,2])

vect1 = 1:5
vect2 = 5:9

arr <- array(c(vect1, vect2), din=c(5, 2, 2))
print(arr)
print(arr[2, , 2])