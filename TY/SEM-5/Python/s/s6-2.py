import tkinter as tk
from tkinter import font

def update_font():
    font_name = font_name_var.get()
    font_size = font_size_var.get()
    is_bold = bold_var.get()
    
    # Construct the font style string
    font_style = (font_name, font_size, 'bold' if is_bold else 'normal')
    
    # Update the label font
    label.config(font=font_style)

# Create the main window
root = tk.Tk()
root.title("Font Style Changer")

# Variables for font settings
font_name_var = tk.StringVar(value='Arial')
font_size_var = tk.IntVar(value=12)
bold_var = tk.BooleanVar(value=False)

# Create and place widgets
label = tk.Label(root, text="Sample Text", font=('Arial', 12))
label.pack(pady=20)

# Font name options
font_names = ['Arial', 'Courier', 'Times New Roman']
tk.Label(root, text="Select Font:").pack()
for name in font_names:
    tk.Radiobutton(root, text=name, variable=font_name_var, value=name, command=update_font).pack()

# Font size options
tk.Label(root, text="Select Font Size:").pack()
font_size_options = [10, 12, 14, 16, 18, 20]
for size in font_size_options:
    tk.Radiobutton(root, text=str(size), variable=font_size_var, value=size, command=update_font).pack()

# Bold check button
tk.Checkbutton(root, text="Bold", variable=bold_var, command=update_font).pack()

# Start the GUI event loop
root.mainloop()
