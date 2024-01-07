# Create an empty list for students
students <- list()

# 1) Give names to the students in the list
student_names <- c("Deva", "Yash", "Tony", "loka")
students <- append(students, student_names)

# 2) Add a student at the end of the list
new_student <- "Adi"
students <- append(students, new_student)

# 3) Remove the first student
students <- students[-1]

# 4) Update the second last student
if (length(students) >= 2) {
  students[length(students) - 1] <- "UpdatedStudent"
}

# Print the updated list of students
print(students)
