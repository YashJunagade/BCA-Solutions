from tkinter import *

def changeBg(c):
  root.config(bg=c)

root = Tk()
root.title("Menu for background change")
root.geometry("400x400")

menuBar = Menu(root)
colorMenu = Menu(menuBar)
colorMenu.add_command(label="Red", command=lambda: changeBg("red"))
colorMenu.add_command(label="Green", command=lambda: changeBg("green"))
colorMenu.add_command(label="Blue", command=lambda: changeBg("blue"))
colorMenu.add_command(label="Yellow", command=lambda: changeBg("yellow"))

menuBar.add_cascade(label="Colors", menu=colorMenu)
root.config(menu=menuBar)

root.mainloop()