class InvalidDateException(Exception):
    pass

class Date:
    def __init__(self):
        self.day = 0
        self.month = 0
        self.year = 0

    def accept(self):
        self.day = int(input("Enter day: "))
        self.month = int(input("Enter month: "))
        self.year = int(input("Enter year: "))
        if not self.is_valid():
            raise InvalidDateException("Invalid Date")

    def display(self):
        print(f"Date: {self.day:02d}/{self.month:02d}/{self.year}")

    def is_valid(self):
        if self.year < 1 or self.month < 1 or self.month > 12 or self.day < 1 or self.day > 31:
            return False
        if self.month in [4, 6, 9, 11] and self.day > 30:
            return False
        if self.month == 2:
            if (self.year % 4 == 0 and self.year % 100 != 0) or (self.year % 400 == 0):
                return self.day <= 29
            return self.day <= 28
        return True

# Example usage
try:
    date = Date()
    date.accept()
    date.display()
except InvalidDateException as e:
    print(f"Error: {e}")
except ValueError:
    print("Error: Please enter valid integers for day, month, and year.")