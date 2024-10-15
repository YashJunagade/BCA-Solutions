from tkinter import *
from tkinter import messagebox

def alterSentence():
    s = entry.get()
    ans = []
    for ch in s:
        if ch.isdigit():
            ans.append('?')
        elif ch.isspace():
            ans.append('*')
        elif ch.isalpha():
            ans.append(ch.upper() if ch.islower else ch.lower())

    ans = ''.join(ans)

    messagebox.showinfo("result", f"{ans}")

root = Tk()
root.title("sentence")

Label(root, text="Enter Sentence : ").pack(pady=(10, 10))
entry = Entry(root)
entry.pack(pady=(5, 5), padx=(20, 20))

Button(root, text="alter", command=alterSentence).pack(pady=(10, 10))

root.mainloop()