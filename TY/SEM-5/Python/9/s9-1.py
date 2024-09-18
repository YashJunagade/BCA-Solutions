class StringReverser:
    def __init__(self, text=""):
        self.text = text

    def set_text(self, text):
        self.text = text

    def reverse_words(self):
        words = self.text.split()
        reversed_words = ' '.join(reversed(words))
        return reversed_words

# Example usage
reverser = StringReverser()

# Input a string
input_text = input("Enter a string: ")
reverser.set_text(input_text)

# Reverse the string word by word and print it
reversed_text = reverser.reverse_words()
print("Reversed string:", reversed_text)
