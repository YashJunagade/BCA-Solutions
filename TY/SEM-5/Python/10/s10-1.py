import tkinter as tk
from tkinter import messagebox

def show_alert():
  messagebox.showinfo("Alert", "Button was pressed!")

# Create the main window
root = tk.Tk()
root.title("Alert Example")

# Create and place a button
button = tk.Button(root, text="Press Me", command=show_alert)
button.pack(pady=20)

# Start the GUI event loop
root.mainloop()
