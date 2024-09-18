import tkinter as tk

# Function to convert digits to words
def digit_to_word(digit):
    words = {
        '0': 'Zero', '1': 'One', '2': 'Two', '3': 'Three', 
        '4': 'Four', '5': 'Five', '6': 'Six', '7': 'Seven', 
        '8': 'Eight', '9': 'Nine'
    }
    return words.get(digit, '')

def display_digits_in_words():
    number = entry.get()
    words_list = [digit_to_word(digit) for digit in number if digit.isdigit()]
    result_label.config(text=' '.join(words_list))

# Set up the main window
root = tk.Tk()
root.title("Digit to Words Converter")

# Create and place the widgets
tk.Label(root, text="Enter a number:").pack(pady=10)

entry = tk.Entry(root)
entry.pack(pady=10)

tk.Button(root, text="Convert to Words", command=display_digits_in_words).pack(pady=10)

result_label = tk.Label(root, text="")
result_label.pack(pady=10)

# Run the application
root.mainloop()
