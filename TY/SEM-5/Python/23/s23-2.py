import math

class Circle:
    def __init__(self, radius):
        self.radius = radius

    def __add__(self, other):
        if isinstance(other, Circle):
            return Circle(self.radius + other.radius)
        return NotImplemented

    def area(self):
        return math.pi * (self.radius ** 2)

    def __str__(self):
        return f"Circle with radius {self.radius:.2f} and area {self.area():.2f}"

# Example usage
circle1 = Circle(5)
circle2 = Circle(3)

# Add the radii of the two circles
circle3 = circle1 + circle2

print(circle1)
print(circle2)
print(circle3)
