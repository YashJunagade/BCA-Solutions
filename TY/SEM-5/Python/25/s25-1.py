def count_case_letters(s):
    upper_count = sum(1 for char in s if char.isupper())
    lower_count = sum(1 for char in s if char.islower())
    return upper_count, lower_count

# Example usage
sample_string = 'The quick Brow Fox'
upper_count, lower_count = count_case_letters(sample_string)

print(f"No. of Upper case characters: {upper_count}")
print(f"No. of Lower case characters: {lower_count}")
