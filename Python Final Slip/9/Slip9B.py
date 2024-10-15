from tkinter import *
from tkinter import messagebox

def isPrime(n):
    if n  <= 1:
       return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


def isPerfect(n):
    return n == sum(i for i in range(1, n) if n % i == 0)

def isArmstrong(n):
   strNum = str(n)
   dlen = len(strNum)

   return n == sum(int(num) ** (dlen) for num in strNum)

   
   

def calculate():
  num = int(entry.get())
  choice = choiceVar.get()

  if choice == "Prime Number":
    if(isPrime(num)):
      messagebox.showinfo("result", f"{num} is a Prime Number")
    else:
      messagebox.showinfo("result", f"{num} is not Prime Number")

  if choice == "Perfect Number":
    if(isPerfect(num)):
      messagebox.showinfo("result", f"{num} is a Perfect Number")
    else:
      messagebox.showinfo("result", f"{num} is not Perfect Number")

  if choice == "Armstrong Number":
    if(isArmstrong(num)):
      messagebox.showinfo("result", f"{num} is a Armstrong Number")
    else:
      messagebox.showinfo("result", f"{num} is not Armstrong Number")


root = Tk()
root.title("Number")

choiceVar = StringVar(value = " ")

Label(root, text="Enter Number : ").pack(pady=(10, 10))
entry = Entry(root)
entry.pack(pady=(10, 10), padx=(10, 10))

for ch in ["Prime Number", "Perfect Number", "Armstrong Number"]:
  Radiobutton(root, text=ch, variable=choiceVar, value=ch).pack(pady=(5, 5), padx=(20, 20))

Button(root, text="calculate", command=calculate).pack()

root.mainloop()
