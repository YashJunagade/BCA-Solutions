from tkinter import *
from tkinter import messagebox

def addItem():
    inp = entry.get()
    if inp:
        listBox.insert(END, inp)
    else :
        messagebox.showinfo("result", "Enter item to add into list")

def printItem():
    select = listBox.curselection()
    if select:
        item = listBox.get(select)
        messagebox.showinfo("result", f"{item}")
    else : 
        messagebox.showinfo("result", f"please select item")

def deleteItem():
    select = listBox.curselection()
    if select:
        listBox.delete(select)
    else :
        messagebox.showinfo("result", f"please select item")


root = Tk()
root.title("ListBox")

Label(root, text="Enter Your List Item : ").pack(pady=(5, 5))
entry = Entry(root)
entry.pack(pady=(10, 10), padx=(30, 30))

Button(root, text="add", command=addItem).pack(pady=(5, 5))
Button(root, text="print", command=printItem).pack(pady=(5, 5))
Button(root, text="delete", command=deleteItem).pack(pady=(5, 5))

listBox = Listbox(root)
listBox.pack(pady=(10, 10))

root.mainloop()




