import tkinter as tk

def change_bg(color):
  root.config(bg=color)

# Create the main window
root = tk.Tk()
root.title("Background Color Changer")
root.geometry("300x200")

# Create a menu bar
menu_bar = tk.Menu(root)

# Create a Color menu
color_menu = tk.Menu(menu_bar, tearoff=0)
color_menu.add_command(label="Red", command=lambda: change_bg("red"))
color_menu.add_command(label="Green", command=lambda: change_bg("green"))
color_menu.add_command(label="Blue", command=lambda: change_bg("blue"))
color_menu.add_command(label="Yellow", command=lambda: change_bg("yellow"))

# Add the Color menu to the menu bar
menu_bar.add_cascade(label="Colors", menu=color_menu)

# Configure the menu bar in the main window
root.config(menu=menu_bar)

# Start the GUI event loop
root.mainloop()
