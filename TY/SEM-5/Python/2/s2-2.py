import tkinter as tk
from time import strftime

def update_time():
    time_string = strftime('%H:%M:%S %p')
    label.config(text=time_string)
    label.after(1000, update_time)  # Update the time every 1000ms (1 second)

# Create the main window
root = tk.Tk()
root.title("Digital Clock")

# Create and place the label widget
label = tk.Label(root, font=('calibri', 40, 'bold'), background='black', foreground='white')
label.pack(anchor='center')

# Start the time update loop
update_time()

# Start the GUI event loop
root.mainloop()
