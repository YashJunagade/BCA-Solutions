import tkinter as tk
from tkinter import ttk
import math

def calculate():
    try:
        radius = float(radius_entry.get())
        height = float(height_entry.get())
        surface_area = 2 * math.pi * radius * (radius + height)
        volume = math.pi * radius**2 * height
        surface_area_label.config(text=f"Surface Area: {surface_area:.2f}")
        volume_label.config(text=f"Volume: {volume:.2f}")
    except ValueError:
        surface_area_label.config(text="Invalid input")
        volume_label.config(text="Invalid input")

# Set up the main window
root = tk.Tk()
root.title("Cylinder Calculator")

# Create and place the widgets
ttk.Label(root, text="Radius:").grid(row=0, column=0, padx=10, pady=10)
radius_entry = ttk.Entry(root)
radius_entry.grid(row=0, column=1, padx=10, pady=10)

ttk.Label(root, text="Height:").grid(row=1, column=0, padx=10, pady=10)
height_entry = ttk.Entry(root)
height_entry.grid(row=1, column=1, padx=10, pady=10)

calculate_button = ttk.Button(root, text="Calculate", command=calculate)
calculate_button.grid(row=2, column=0, columnspan=2, padx=10, pady=10)

surface_area_label = ttk.Label(root, text="Surface Area:")
surface_area_label.grid(row=3, column=0, columnspan=2, padx=10, pady=10)

volume_label = ttk.Label(root, text="Volume:")
volume_label.grid(row=4, column=0, columnspan=2, padx=10, pady=10)

# Run the application
root.mainloop()
