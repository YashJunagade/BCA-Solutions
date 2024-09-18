class Student:
    def __init__(self, student_name, marks):
        self.student_name = student_name
        self.marks = marks

    def modify_attributes(self, new_name, new_marks):
        self.student_name = new_name
        self.marks = new_marks

    def print_attributes(self):
        print(f"Student Name: {self.student_name}")
        print(f"Marks: {self.marks}")

# Create a Student object
student = Student("John Doe", 85)

# Print original values
print("Original values:")
student.print_attributes()

# Modify attributes
student.modify_attributes("Jane Smith", 92)

# Print modified values
print("\nModified values:")
student.print_attributes()
