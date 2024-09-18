import tkinter as tk
import random

def change_color():
    colors = ['red', 'green', 'blue', 'yellow', 'purple', 'orange', 'pink']
    new_color = random.choice(colors)
    root.config(bg=new_color)
    root.after(1000, change_color)  # Change color every 1000ms (1 second)

# Create the main window
root = tk.Tk()
root.title("Color Changing Background")

# Set initial color and start color change loop
change_color()

# Start the GUI event loop
root.mainloop()
