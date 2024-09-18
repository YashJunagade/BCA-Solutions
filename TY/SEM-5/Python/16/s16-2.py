import tkinter as tk
from tkinter import messagebox

def add_item():
    item = entry.get()
    if item:
        listbox.insert(tk.END, item)
        entry.delete(0, tk.END)
    else:
        messagebox.showwarning("Warning", "Please enter an item.")

def print_selected():
    selected = listbox.curselection()
    if selected:
        item = listbox.get(selected[0])
        messagebox.showinfo("Selected Item", f"Selected item: {item}")
    else:
        messagebox.showwarning("Warning", "No item selected.")

def delete_selected():
    selected = listbox.curselection()
    if selected:
        listbox.delete(selected[0])
    else:
        messagebox.showwarning("Warning", "No item selected.")

# Set up the main window
root = tk.Tk()
root.title("Listbox Manager")

# Create and place the widgets
entry = tk.Entry(root)
entry.pack(pady=10)

tk.Button(root, text="Add Item", command=add_item).pack(pady=5)
tk.Button(root, text="Print Selected", command=print_selected).pack(pady=5)
tk.Button(root, text="Delete Selected", command=delete_selected).pack(pady=5)

listbox = tk.Listbox(root)
listbox.pack(pady=10)

# Run the application
root.mainloop()
