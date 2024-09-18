def update_dict(d, old_key, new_key, new_value):
    if old_key in d:
        del d[old_key]  # Remove the old key
    d[new_key] = new_value  # Add the new key/value pair

# Example usage
my_dict = {'a': 1, 'b': 2, 'c': 3}
print("Original dictionary:", my_dict)

update_dict(my_dict, 'b', 'd', 4)
print("Updated dictionary:", my_dict)
