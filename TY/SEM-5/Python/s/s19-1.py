import tkinter as tk

def display_table():
    num = int(entry.get())
    result_text = "\n".join(f"{num} x {i} = {num * i}" for i in range(1, 11))
    result_label.config(text=result_text)

# Set up the main window
root = tk.Tk()
root.title("Multiplication Table")

# Create and place the widgets
tk.Label(root, text="Enter a number:").pack(pady=10)

entry = tk.Entry(root)
entry.pack(pady=10)

tk.Button(root, text="Show Table", command=display_table).pack(pady=10)

result_label = tk.Label(root, text="")
result_label.pack(pady=10)

# Run the application
root.mainloop()
