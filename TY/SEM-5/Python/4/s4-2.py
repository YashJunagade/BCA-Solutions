class Employee:
    def __init__(self, id, name, department, salary):
        self.id = id
        self.name = name
        self.department = department
        self.salary = salary

    def accept(self):
        self.id = input("Enter ID: ")
        self.name = input("Enter Name: ")
        self.department = input("Enter Department: ")
        self.salary = float(input("Enter Salary: "))

    def display(self):
        print(f"ID: {self.id}")
        print(f"Name: {self.name}")
        print(f"Department: {self.department}")
        print(f"Salary: {self.salary}")

class Manager(Employee):
    def __init__(self, id, name, department, salary, bonus):
        super().__init__(id, name, department, salary)
        self.bonus = bonus

    def accept(self):
        super().accept()
        self.bonus = float(input("Enter Bonus: "))

    def display(self):
        super().display()
        print(f"Bonus: {self.bonus}")
        print(f"Total Salary (Salary + Bonus): {self.total_salary()}")

    def total_salary(self):
        return self.salary + self.bonus

# Function to find and display the manager with the maximum total salary
def find_max_salary_manager(managers):
    max_manager = max(managers, key=lambda m: m.total_salary())
    print("\nManager with the Maximum Total Salary:")
    max_manager.display()

# Creating and accepting manager objects
n = int(input("Enter number of managers: "))
managers = []

for _ in range(n):
    print("\nEnter details for manager:")
    manager = Manager('', '', '', 0, 0)
    manager.accept()
    managers.append(manager)

# Finding and displaying the manager with the maximum total salary
find_max_salary_manager(managers)
