def count_case(s):
    upper_count = sum(1 for char in s if char.isupper())
    lower_count = sum(1 for char in s if char.islower())
    print(f"No. of Upper case characters: {upper_count}")
    print(f"No. of Lower case characters: {lower_count}")

# Example usage
sample_string = 'The quick Brown Fox'
count_case(sample_string)
