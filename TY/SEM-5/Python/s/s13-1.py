while True:
    try:
        num = int(input("Enter a positive integer: "))
        if num <= 0:
            raise ValueError
        print(f"Correct input! You entered: {num}")
        break
    except ValueError:
        print("Incorrect input. Please enter a positive integer.")