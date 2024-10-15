from tkinter import *
from tkinter import messagebox

def changeCase():
    s = str.get()
    messagebox.showinfo("Answer : ", f"{s.upper()}")

root = Tk()
root.title("Uppercase input")

Label(root, text="Enter String : ").pack(pady=(10, 10))
str = Entry(root)
str.pack(padx=(20, 20))

Button(root, text="click here", command=changeCase).pack(pady=(10, 10))

root.mainloop()
