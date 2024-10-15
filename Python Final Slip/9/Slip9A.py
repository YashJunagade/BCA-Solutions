class ReverseString:
    def __init__(self, str):
        self.str = str

    def reverseStr(self):
        words = self.str.split();
        reverseWords = ' '.join(reversed(words))
        print("Reverse String Word by Word : ", reverseWords)


str = input("Enter String : ")
revStr = ReverseString(str)
revStr.reverseStr()

