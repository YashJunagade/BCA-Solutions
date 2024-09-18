import tkinter as tk
from tkinter import messagebox
from datetime import datetime

def calculate_age():
    try:
        birthdate = datetime.strptime(entry.get(), "%Y-%m-%d")
        today = datetime.today()
        age = today.year - birthdate.year - ((today.month, today.day) < (birthdate.month, birthdate.day))
        messagebox.showinfo("Age", f"Your age is {age} years old.")
    except ValueError:
        messagebox.showerror("Invalid Input", "Enter date in YYYY-MM-DD format.")

# Create the main window
root = tk.Tk()
root.title("Age Calculator")

# Create and place widgets
tk.Label(root, text="Enter your birthdate (YYYY-MM-DD):").pack(pady=10)
entry = tk.Entry(root)
entry.pack(pady=5)
tk.Button(root, text="Calculate Age", command=calculate_age).pack(pady=20)

# Start the GUI event loop
root.mainloop()
