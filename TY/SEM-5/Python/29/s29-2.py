def sort_by_key(d, reverse=False):
    return dict(sorted(d.items(), key=lambda item: item[0], reverse=reverse))

def sort_by_value(d, reverse=False):
    return dict(sorted(d.items(), key=lambda item: item[1], reverse=reverse))

# Example dictionary
my_dict = {'apple': 3, 'banana': 1, 'cherry': 2, 'date': 4}

# Sort by key (ascending and descending)
sorted_by_key_asc = sort_by_key(my_dict)
sorted_by_key_desc = sort_by_key(my_dict, reverse=True)

# Sort by value (ascending and descending)
sorted_by_value_asc = sort_by_value(my_dict)
sorted_by_value_desc = sort_by_value(my_dict, reverse=True)

print("Original dictionary:", my_dict)
print("Sorted by key (ascending):", sorted_by_key_asc)
print("Sorted by key (descending):", sorted_by_key_desc)
print("Sorted by value (ascending):", sorted_by_value_asc)
print("Sorted by value (descending):", sorted_by_value_desc)
