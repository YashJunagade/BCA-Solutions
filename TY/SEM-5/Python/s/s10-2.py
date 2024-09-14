class ParenthesesValidator:
  def __init__(self, string):
    self.string = string

  def is_valid(self):
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}

    for char in self.string:
      if char in mapping.values():
        stack.append(char)
      elif char in mapping.keys():
        if stack == [] or mapping[char] != stack.pop():
          return False
    return stack == []

# Example usage
validator = ParenthesesValidator("({[]})")
print("Valid" if validator.is_valid() else "Invalid")

validator = ParenthesesValidator("({[)]}")
print("Valid" if validator.is_valid() else "Invalid")
