from tkinter import *
from time import *

def updateTime():
  t = strftime("%H : %M : %S %p")
  timeLabel.config(text=t)
  timeLabel.after(1000, updateTime)

root = Tk()
root.title("Digital Clock")

timeLabel = Label(root)
timeLabel.pack()

updateTime()

root.mainloop()

