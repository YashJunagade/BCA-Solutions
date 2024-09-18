import tkinter as tk
from tkinter import font

def change_font():
    # Define the new font style
    new_font = font.Font(family="Helvetica", size=16, weight="bold")
    label.config(font=new_font)

# Set up the main window
root = tk.Tk()
root.title("Change Font Style")

# Create and place the label
label = tk.Label(root, text="Sample Text", font=("Arial", 12))
label.pack(pady=20)

# Create and place the button
button = tk.Button(root, text="Change Font", command=change_font)
button.pack(pady=20)

# Run the application
root.mainloop()
