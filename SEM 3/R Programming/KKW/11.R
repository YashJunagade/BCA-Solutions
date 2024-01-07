v1 = c(10, 20, 30, 40)
v2 = c(1, 2, 3)

arr1 = array(c(v1, v2), dim=c(2, 2, 2))
arr2 = array(c(v2, v1), dim = c(2, 2, 2))
add = arr1 + arr2
sub = arr1 - arr2

cat("Array 1 :\n")
print(arr1)
cat("Array 2 :\n")
print(arr2)

cat("Addition :\n")
print(add)
cat("Subtraction :\n")
print(sub)