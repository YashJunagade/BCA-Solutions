def fibonacci_generator():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b

# Create a generator object
fib_gen = fibonacci_generator()

# Number of Fibonacci terms to generate
n = int(input("Enter the number of Fibonacci terms to generate: "))

# Generate and print Fibonacci terms
for _ in range(n):
    print(next(fib_gen))
