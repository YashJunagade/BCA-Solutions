import tkinter as tk
from tkinter import messagebox

def count_char():
    s = entry_string.get()
    c = entry_char.get()
    if len(c) != 1:
        messagebox.showerror("Error", "Enter exactly one character.")
        return
    count = s.count(c)
    result_label.config(text=f"Occurrences: {count}")

root = tk.Tk()
root.title("Character Counter")

tk.Label(root, text="String:").pack()
entry_string = tk.Entry(root)
entry_string.pack()

tk.Label(root, text="Character:").pack()
entry_char = tk.Entry(root, width=5)
entry_char.pack()

tk.Button(root, text="Count", command=count_char).pack()
result_label = tk.Label(root, text="")
result_label.pack()

root.mainloop()
