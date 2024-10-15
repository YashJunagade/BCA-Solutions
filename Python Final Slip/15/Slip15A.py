class Student:
    def __init__(self, n, m):
        self.name = n
        self.marks = m

    def modify(self, n, m):
        self.name = n
        self.marks = m

    def showData(self):
        print(f"Name : {self.name}")
        print(f"Marks : {self.marks}")


s1 = Student("Yash Junagade", 99)
print("Original Data : ")
s1.showData()

print("Modify Data : ")
s1.modify("Tony", 98)
s1.showData()

