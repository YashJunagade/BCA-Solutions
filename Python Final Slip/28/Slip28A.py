from tkinter import *

root = Tk()
root.title("Listbox")

listbox = Listbox(root)
listbox.pack(pady=(10, 10))

for item in ["C Programming", "DBMS", "Web Technology", "RDBMS", "Data Structure", "CPP", "Java", "Python"]:
    listbox.insert(END, item)    

root.mainloop()
