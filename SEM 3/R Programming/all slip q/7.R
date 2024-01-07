# Create a data frame with employee details
employees <- data.frame(
  EmployeeID = c(1, 2, 3, 4, 5),
  Name = c("Gorkha", "Adi", "Maratha", "Loka", "Sharper"),
  Department = c("HR", "IT", "Finance", "Sales", "Marketing"),
  Salary = c(55000, 60000, 65000, 60000, 62000)
)

# Display the data frame in ascending order by employee names
sorted_employees <- employees[order(employees$Name), ]
print(sorted_employees)
