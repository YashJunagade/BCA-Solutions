class Rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width

    def perimeter(self):
        return 2 * (self.length + self.width)

# Example usage
length = float(input("Enter the length of the rectangle: "))
width = float(input("Enter the width of the rectangle: "))

rectangle = Rectangle(length, width)

print(f"Area of the rectangle: {rectangle.area()}")
print(f"Perimeter of the rectangle: {rectangle.perimeter()}")
