import tkinter as tk

def convert_number():
    try:
        decimal_number = int(entry.get())
        binary_rep = bin(decimal_number)[2:]  # Convert to binary and remove '0b'
        octal_rep = oct(decimal_number)[2:]   # Convert to octal and remove '0o'
        hexadecimal_rep = hex(decimal_number)[2:].upper()  # Convert to hexadecimal and remove '0x'
        
        binary_label.config(text=f"Binary: {binary_rep}")
        octal_label.config(text=f"Octal: {octal_rep}")
        hexadecimal_label.config(text=f"Hexadecimal: {hexadecimal_rep}")
    except ValueError:
        binary_label.config(text="Invalid input. Please enter a valid decimal number.")
        octal_label.config(text="")
        hexadecimal_label.config(text="")

# Set up the main window
root = tk.Tk()
root.title("Number Converter")

# Create and place the widgets
tk.Label(root, text="Enter a decimal number:").pack(pady=10)

entry = tk.Entry(root)
entry.pack(pady=10)

tk.Button(root, text="Convert", command=convert_number).pack(pady=10)

binary_label = tk.Label(root, text="")
binary_label.pack(pady=5)

octal_label = tk.Label(root, text="")
octal_label.pack(pady=5)

hexadecimal_label = tk.Label(root, text="")
hexadecimal_label.pack(pady=5)

# Run the application
root.mainloop()
