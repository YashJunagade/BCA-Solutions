class Rectangle:
    def __init__(self, l, w):
        self.l = l
        self.w = w

    def area(self):
        return l * w

    def perimeter(self):
        return 2 * (l + w)


l = int(input("Enter Length : "))
w = int(input("Enter Width : "))

r = Rectangle(l, w)
print(f"Area of Rectangle : {r.area()}")
print(f"Perimeter of Rectangle : {r.perimeter()}")

