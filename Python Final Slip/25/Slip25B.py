class Calculator:
    def __init__(self, n1, n2):
        self.n1 = n1
        self.n2 = n2


    def add(self):
        return self.n1 + self.n2

    def sub(self):
        return self.n1 - self.n2

    def multiply(self):
        return self.n1 * self.n2

    def divide(self):
        return self.n1 / self.n2



n1 = int(input("Enter First Number : "))
n2 = int(input("Enter Second Number : "))

c = Calculator(n1, n2)
print("Addition : ", c.add())
print("Subtraction : ", c.sub())
print("Multiplication : ", c.multiply())
print("Divison : ", c.divide())
