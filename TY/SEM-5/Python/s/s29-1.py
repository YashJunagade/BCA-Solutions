import tkinter as tk
from tkinter import messagebox
import math

def calculate_volume():
    try:
        # Get the radius from the input
        radius = float(entry.get())
        # Calculate the volume of the sphere
        volume = (4/3) * math.pi * (radius ** 3)
        # Display the result
        result_label.config(text=f"Volume of the sphere: {volume:.2f}")
    except ValueError:
        # Handle invalid input
        messagebox.showerror("Invalid input", "Please enter a valid number.")

# Set up the main window
root = tk.Tk()
root.title("Sphere Volume Calculator")

# Create and place the widgets
tk.Label(root, text="Enter the radius of the sphere:").pack(pady=10)

entry = tk.Entry(root)
entry.pack(pady=10)

tk.Button(root, text="Calculate Volume", command=calculate_volume).pack(pady=10)

result_label = tk.Label(root, text="")
result_label.pack(pady=10)

# Run the application
root.mainloop()
