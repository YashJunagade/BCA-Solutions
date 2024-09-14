import tkinter as tk

def convert_to_uppercase():
    input_text = entry.get()
    result_label.config(text=f"Uppercase Text: {input_text.upper()}")

# Set up the main window
root = tk.Tk()
root.title("Uppercase Converter")

# Create and place the widgets
tk.Label(root, text="Enter text:").pack(pady=10)

entry = tk.Entry(root, width=40)
entry.pack(pady=10)

convert_button = tk.Button(root, text="Convert to Uppercase", command=convert_to_uppercase)
convert_button.pack(pady=10)

result_label = tk.Label(root, text="Uppercase Text: ")
result_label.pack(pady=10)

# Run the application
root.mainloop()
