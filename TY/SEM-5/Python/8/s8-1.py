def find_repeated_items(t):
    from collections import Counter
    counts = Counter(t)
    repeated = [item for item, count in counts.items() if count > 1]
    return repeated

# Example usage
t = (1, 2, 3, 2, 4, 5, 1, 6, 7, 1)
repeated_items = find_repeated_items(t)
print("Repeated items:", repeated_items)
