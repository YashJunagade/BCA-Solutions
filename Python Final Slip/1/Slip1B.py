from tkinter import *
from datetime import datetime
from tkinter import messagebox


def calculateAge():
    birth = datetime.strptime(dateInp.get(), "%Y-%m-%d")
    t = datetime.today()
    age = t.year - birth.year

    if(t.month < birth.month):
        age -= 1

    messagebox.showinfo("Result", f"Your Age is : {age}")



root = Tk()
root.title("Age Calculator")

Label(root, text="Enter Birthdate(yyyy-mm-dd) : ").pack(pady=(10, 10))
dateInp = Entry(root)
dateInp.pack(padx=(20, 20), pady=(10, 10))
calBtn = Button(root, text="Calcalute", command=calculateAge)
calBtn.pack()

root.mainloop()
