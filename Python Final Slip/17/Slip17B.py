class InvalidDate(Exception):
    pass


class Date:
    def __init__(self):
        self.d = 0
        self.m = 0
        self.y = 0

    def accept(self):
        self.d = int(input("Enter Day : "))
        self.m = int(input("Enter Month : "))
        self.y = int(input("Enter Year : "))

    def display(self):
        print(f"Day : {self.d}")
        print(f"Month : {self.m}")
        print(f"Year : {self.y}")

    def check(self):
        if(self.d < 0 or self.m < 0 or self.y < 0):
            raise InvalidDate("Invali Date Exception") 
        print("Valid Date")
        
try:    
    d = Date()
    d.accept()
    d.display()
    d.check()
except InvalidDate as e:
    print(e)



