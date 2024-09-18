def generate_square_dict(n):
    return {x: x * x for x in range(1, n + 1)}

# Example usage
n = 5
square_dict = generate_square_dict(n)
print(square_dict)
