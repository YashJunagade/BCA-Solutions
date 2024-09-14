class Student:
    def __init__(self, roll_no, name, age, gender):
        self.roll_no = roll_no
        self.name = name
        self.age = age
        self.gender = gender

class Test(Student):
    def __init__(self, roll_no, name, age, gender, marks1, marks2, marks3):
        super().__init__(roll_no, name, age, gender)
        self.marks1 = marks1
        self.marks2 = marks2
        self.marks3 = marks3

    def total_marks(self):
        return self.marks1 + self.marks2 + self.marks3

    def display(self):
        print(f"Roll No: {self.roll_no}")
        print(f"Name: {self.name}")
        print(f"Age: {self.age}")
        print(f"Gender: {self.gender}")
        print(f"Marks: {self.marks1}, {self.marks2}, {self.marks3}")
        print(f"Total Marks: {self.total_marks()}")

# Creating objects of the Test class
student1 = Test('001', 'Yash', 20, 'F', 85, 90, 88)
student2 = Test('002', 'Dipak', 21, 'M', 78, 82, 79)
student3 = Test('003', 'Tony', 22, 'M', 92, 94, 89)

# Displaying details of all students
print("Student 1 Details:")
student1.display()
print("\nStudent 2 Details:")
student2.display()
print("\nStudent 3 Details:")
student3.display()
