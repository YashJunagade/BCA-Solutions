import math

class Shape:
    def area(self):
        raise NotImplementedError("Subclass must implement this method")

    def volume(self):
        raise NotImplementedError("Subclass must implement this method")

class Square(Shape):
    def __init__(self, length):
        self.length = length

    def area(self):
        return self.length ** 2

    def volume(self):
        return "Volume not applicable for 2D shape"

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius ** 2

    def volume(self):
        return "Volume not applicable for 2D shape"

# Example usage
square = Square(4)
circle = Circle(3)

print(f"Square Area: {square.area()}")
print(f"Square Volume: {square.volume()}")

print(f"Circle Area: {circle.area()}")
print(f"Circle Volume: {circle.volume()}")
