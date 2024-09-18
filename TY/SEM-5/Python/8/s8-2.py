class StringManipulator:
    def __init__(self):
        self.text = ""

    def get_String(self):
        self.text = input("Enter a string: ")

    def print_String(self):
        print(self.text.upper())

    def reverse_words(self):
        words = self.text.split()
        reversed_words = ' '.join(reversed(words))
        print(reversed_words.lower())

# Example usage
manipulator = StringManipulator()

# Get a string from the user
manipulator.get_String()

# Print the string in uppercase
manipulator.print_String()

# Print the reversed words in lowercase
manipulator.reverse_words()
