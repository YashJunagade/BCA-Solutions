class StringManipulator:
 def __init__(self):
  self.text = ""

 def get_String(self):
  self.text = input("Enter a string: ")

 def print_String(self):
  print(self.text.upper())

# Create an instance of StringManipulator
string_manipulator = StringManipulator()

# Accept a string from the user
string_manipulator.get_String()

# Print the string in uppercase
string_manipulator.print_String()
