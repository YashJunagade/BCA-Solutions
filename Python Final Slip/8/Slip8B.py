class Str:
    def __init__(self):
        self.s = ""

    def getString(self):
        self.s = input("Enter String : ")

    def printString(self):
        print(self.s.upper())

    def reverseString(self):
        words = self.s.split(" ")
        reverseWord = ' '.join(reversed(words))
        print(reverseWord)


s = Str()
s.getString()
s.printString()
s.reverseString()

