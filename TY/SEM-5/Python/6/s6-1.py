#create package
import math

def cube_area(side_length):
 return 6 * (side_length ** 2)

def cube_volume(side_length):
 return side_length ** 3

def sphere_area(radius):
 return 4 * math.pi * (radius ** 2)

def sphere_volume(radius):
 return (4/3) * math.pi * (radius ** 3)

#main.py

from geometry.shapes import cube_area, cube_volume, sphere_area, sphere_volume

def main():
 # Cube
 side_length = float(input("Enter the side length of the cube: "))
 print(f"Cube Area: {cube_area(side_length)}")
 print(f"Cube Volume: {cube_volume(side_length)}")

 # Sphere
 radius = float(input("Enter the radius of the sphere: "))
 print(f"Sphere Surface Area: {sphere_area(radius)}")
 print(f"Sphere Volume: {sphere_volume(radius)}")

if __name__ == "__main__":
 main()
