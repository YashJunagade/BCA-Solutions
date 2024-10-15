from tkinter import *

def changeStyle():
  fontFamily = fontFamilyVar.get()
  fontSize = fontSizeVar.get()
  isBold = fontBoldVar.get()

  sampleText.config(font=(fontFamily, fontSize, 'bold' if isBold else 'normal'))

root = Tk()
root.title("Font Style")

fontFamilyVar = StringVar(value = "Arial")
fontSizeVar = StringVar(value = 10)
fontBoldVar = BooleanVar(value = False)

sampleText = Label(root, text="Sample Text")
sampleText.pack(pady=(10, 10))

Label(root, text="Choose any font family :").pack(pady=(10, 10), padx=(20, 20))
for font in ["Arial", "Verdana", "Times New Roman"]:
  Radiobutton(root, text=font, variable=fontFamilyVar, value=font, command=changeStyle).pack(pady=(5, 5))

Label(root, text="Choose any font size : ").pack(pady=(10, 10))
for size in [12, 16, 20, 24]:
  Radiobutton(root, text=size, variable=fontSizeVar, value=size, command=changeStyle).pack(pady=(5, 5))

Checkbutton(root, text="Bold Text", variable=fontBoldVar, command=changeStyle).pack(pady=(5, 5))


root.mainloop()


