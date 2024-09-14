# Lambda function to find the area of a square
area_of_square = lambda side: side * side

# Lambda function to find the area of a rectangle
area_of_rectangle = lambda length, width: length * width

# Example usage
side = float(input("Enter the side length of the square: "))
length = float(input("Enter the length of the rectangle: "))
width = float(input("Enter the width of the rectangle: "))

print(f"Area of the square: {area_of_square(side)}")
print(f"Area of the rectangle: {area_of_rectangle(length, width)}")
