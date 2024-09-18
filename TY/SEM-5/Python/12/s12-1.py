import tkinter as tk
from tkinter import font

def update_font():
  selected_font = font_name_var.get()
  size = int(font_size_entry.get())
  weight = 'bold' if bold_var.get() else 'normal'
  label.config(font=(selected_font, size, weight))

# Create main window
root = tk.Tk()
root.title("Font Style Changer")
root.geometry("300x200")

# Variables for font settings
font_name_var = tk.StringVar(value="Arial")
bold_var = tk.BooleanVar()
font_size_var = tk.IntVar(value=12)

# Label to display
label = tk.Label(root, text="Sample Text", font=("Arial", 12))
label.pack(pady=10)

# Font name dropdown
font_name_label = tk.Label(root, text="Select Font:")
font_name_label.pack()
font_name_menu = tk.OptionMenu(root, font_name_var, "Arial", "Courier", "Times New Roman", "Helvetica")
font_name_menu.pack()

# Font size entry
font_size_label = tk.Label(root, text="Enter Font Size:")
font_size_label.pack()
font_size_entry = tk.Entry(root)
font_size_entry.pack()
font_size_entry.insert(0, "12")

# Bold check button
bold_check = tk.Checkbutton(root, text="Bold", variable=bold_var, command=update_font)
bold_check.pack()

# Update button to apply changes
update_button = tk.Button(root, text="Update Font", command=update_font)
update_button.pack(pady=10)

# Start the GUI event loop
root.mainloop()
