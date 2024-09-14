class Person:
    def __init__(self, name, address):
        self.name = name
        self.address = address

class Employee(Person):
    def __init__(self, name, address, staff_id, salary):
        super().__init__(name, address)
        self.staff_id = staff_id
        self.salary = salary

    def display(self):
        print(f"Name: {self.name}")
        print(f"Address: {self.address}")
        print(f"Staff ID: {self.staff_id}")
        print(f"Salary: {self.salary}")
        print()

# Number of employees
n = int(input("Enter the number of employees: "))

employees = []
for _ in range(n):
    name = input("Enter name: ")
    address = input("Enter address: ")
    staff_id = input("Enter staff ID: ")
    salary = float(input("Enter salary: "))
    emp = Employee(name, address, staff_id, salary)
    employees.append(emp)

# Display all employee details
for emp in employees:
    emp.display()
