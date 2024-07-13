import subprocess
from python_tkinterMini.tkinterMini import SimpleGUI
import tkinter as tk
import tkinter.font as tkFont
n = 0

# create the app instance
app = SimpleGUI(title="Tkinter Example", width=1000, height=500)
custom_font = tkFont.Font(family="Comic Sans", size=20, weight="bold", slant="italic")

# Set background color
app.root.configure(bg='lightblue')

label1 = app.add_label("I am a Funny Guy", row=0, column=0)
label1.config(fg='red', bg='lightblue', font=custom_font)

label = app.add_label("", row=0, column=10)
label.place(relx=0.5, rely=0.5, anchor='center')
label.config(fg='blue', bg='yellow', font=custom_font)

def on_button_click():
    global n
    result = subprocess.run(['./jokeWriter'], text=True, capture_output=True)
    
    label.config(text=result.stdout)
    
app.add_button("Jokes", command=on_button_click, row=1, column=0)

app.run()

