import tkinter as tk
import random
import string

def generate_password():
    length = int(length_entry.get())
    characters = string.ascii_letters
    password = ''.join(random.choice(characters) for _ in range(length))
    password_var.set(password)

# Create the main window
root = tk.Tk()
root.title("Password Generator")

# Create and place widgets
tk.Label(root, text="Password Length:").pack(pady=10)
length_entry = tk.Entry(root)
length_entry.pack(pady=5)

tk.Button(root, text="Generate Password", command=generate_password).pack(pady=10)

password_var = tk.StringVar()
tk.Entry(root, textvariable=password_var, state='readonly', width=40).pack(pady=10)

# Start the GUI event loop
root.mainloop()
