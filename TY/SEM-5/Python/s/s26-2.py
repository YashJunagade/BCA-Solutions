import tkinter as tk

def alter_sentence():
    # Get the input sentence
    sentence = entry.get()
    # Create a new altered sentence
    altered = []
    for char in sentence:
        if char.isdigit():
            altered.append('?')
        elif char.isalpha():
            altered.append(char.upper() if char.islower() else char.lower())
        elif char.isspace():
            altered.append('*')
        else:
            altered.append(char)
    # Update the result label with the altered sentence
    result_label.config(text=''.join(altered))

# Set up the main window
root = tk.Tk()
root.title("Alter Sentence")

# Create and place the widgets
tk.Label(root, text="Enter a sentence:").pack(pady=10)

entry = tk.Entry(root, width=50)
entry.pack(pady=10)

tk.Button(root, text="Alter Sentence", command=alter_sentence).pack(pady=10)

result_label = tk.Label(root, text="", wraplength=400)
result_label.pack(pady=10)

# Run the application
root.mainloop()
