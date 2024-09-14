from collections import Counter

def count_repeated_chars(s):
  counter = Counter(s)
  repeated_chars = {char: count for char, count in counter.items() if count > 1}
  return repeated_chars

# Sample string
s = 'thequickbrownfoxjumpsoverthelazydog'

# Get repeated characters
result = count_repeated_chars(s)

# Display the output
for char, count in result.items():
  print(f"{char}-{count}")
