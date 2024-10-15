class Userstr:
    str = "";

    def get_String(self):
        self.str = input("Enter String : ")

    def print_String(self):
        print(self.str)


s = Userstr()

s.get_String()
s.print_String()
