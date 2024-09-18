# Original tuple of string values
original_tuple = (('333', '33'), ('1416', '55'))

# Convert tuple of string values to tuple of integer values
converted_tuple = tuple(tuple(int(x) for x in sub_tuple) for sub_tuple in original_tuple)

print("Original tuple values:", original_tuple)
print("New tuple values:", converted_tuple)
