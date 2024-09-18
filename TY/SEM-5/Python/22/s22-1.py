class Repeater:
    def __init__(self, text):
        self.text = text

    def __mul__(self, n):
        if isinstance(n, int) and n > 0:
            return self.text * n
        else:
            raise ValueError("Multiplier must be a positive integer")

# Example usage
text = input("Enter a string: ")
n = int(input("Enter a number: "))

repeater = Repeater(text)

try:
    result = repeater * n
    print("Repeated string:", result)
except ValueError as e:
    print(e)
