import tkinter as tk
from tkinter import messagebox

def is_prime(n):
 if n <= 1:
  return False
 for i in range(2, int(n**0.5) + 1):
  if n % i == 0:
   return False
 return True

def is_perfect(n):
 return n == sum(i for i in range(1, n) if n % i == 0)

def is_armstrong(n):
 digits = [int(d) for d in str(n)]
 power = len(digits)
 return n == sum(d ** power for d in digits)

def check_number():
 try:
  n = int(entry.get())
 except ValueError:
  messagebox.showerror("Input Error", "Please enter a valid integer.")
  return

 if var.get() == 'Prime':
  result = is_prime(n)
  message = f"{n} is {'a Prime number' if result else 'not a Prime number'}."
 elif var.get() == 'Perfect':
  result = is_perfect(n)
  message = f"{n} is {'a Perfect number' if result else 'not a Perfect number'}."
 elif var.get() == 'Armstrong':
  result = is_armstrong(n)
  message = f"{n} is {'an Armstrong number' if result else 'not an Armstrong number'}."
 else:
  message = "Please select a number type to check."
 
 messagebox.showinfo("Result", message)

# Create the main window
root = tk.Tk()
root.title("Number Checker")

# Create and place widgets
tk.Label(root, text="Enter a number:").pack(pady=10)
entry = tk.Entry(root)
entry.pack(pady=5)

var = tk.StringVar(value='Prime')
tk.Radiobutton(root, text="Prime", variable=var, value='Prime').pack()
tk.Radiobutton(root, text="Perfect", variable=var, value='Perfect').pack()
tk.Radiobutton(root, text="Armstrong", variable=var, value='Armstrong').pack()

tk.Button(root, text="Check", command=check_number).pack(pady=20)

# Start the GUI event loop
root.mainloop()
