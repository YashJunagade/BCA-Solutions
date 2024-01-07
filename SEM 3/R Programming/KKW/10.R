# Create a list of cities
cities <- list("Nashik", "Mumbai", "Pune", "Hydrabad")

# 1) Give names to the elements in the list
names(cities) <- c("City1", "City2", "City3", "City4")

# Display the list with names
cat("List with Names:\n")
print(cities)

# 2) Add an element at the end of the list
cities[["City5"]] <- "Delhi"

# Display the updated list
cat("\nList with Added Element:\n")
print(cities)

# 3) Remove the last element
cities <- cities[-length(cities)]

# Display the list after removing the last element
cat("\nList with Last Element Removed:\n")
print(cities)

# 4) Update the 3rd Element
cities[["City3"]] <- "New York"

# Display the list after updating the 3rd element
cat("\nList with 3rd Element Updated:\n")
print(cities)
