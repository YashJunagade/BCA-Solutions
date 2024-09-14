class Calculator:
    def add(self, a, b):
        return a + b

    def subtract(self, a, b):
        return a - b

    def multiply(self, a, b):
        return a * b

    def divide(self, a, b):
        if b != 0:
            return a / b
        else:
            raise ValueError("Cannot divide by zero")

# Example usage
calc = Calculator()

# Input numbers
a = float(input("Enter the first number: "))
b = float(input("Enter the second number: "))

# Perform operations
print(f"Addition: {calc.add(a, b)}")
print(f"Subtraction: {calc.subtract(a, b)}")
print(f"Multiplication: {calc.multiply(a, b)}")
try:
    print(f"Division: {calc.divide(a, b)}")
except ValueError as e:
    print(e)
