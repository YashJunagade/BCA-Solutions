import math

class Circle:
    def __init__(self, r):
        self.r = r

    def area(self):
        return math.pi * (self.r ** 2)

    def perimeter(self):
        return 2 * math.pi * (self.r ** 2)


r = int(input("Enter the radius of Circle : "))
c = Circle(r)
print(f"Area of Circle : {c.area()}")
print(f"Perimeter of Circle : {c.perimeter()}")
