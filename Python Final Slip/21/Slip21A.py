class Rectangle:
    def __init__(self, l, w):
      self.l = l
      self.w = w

    def area(self):
        return self.l * self.w


    def perimeter(self):
        return 2 * (self.l + self.w)


l = int(input("Enter length of rectangle : "))
w = int(input("Enter width of rectangle : "))

r = Rectangle(l, w)
print(f"Area of Rectangle : {r.area()}")
print(f"Perimeter of Rectangle : {r.perimeter()}")
