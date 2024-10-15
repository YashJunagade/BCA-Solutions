area = lambda side : side * side
rarea = lambda l, w : l * w

s = int(input("Enter Side of Square : "))
l = int(input("Enter Length of rectangle : "))
w = int(input("Enter Width of rectangle : "))

print("Area of Square : ", area(s))
print("Area of Rectangle : ", rarea(l, w))