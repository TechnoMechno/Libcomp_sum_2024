import subprocess
from python_tkinterMini.tkinterMini import SimpleGUI
import tkinter as tk
import tkinter.font as tkFont
from PIL import Image, ImageTk
n = 0

# create the app instance
app = SimpleGUI(title="Tkinter Example", width=1000, height=500)
custom_font = tkFont.Font(family="Comic Sans", size=20, weight="bold", slant="italic")

# Set background color
# Load and display the image
image_path = '/Users/ajalagao/Desktop/Libcomp/Libcomp_sum_2024/blurry-beach-background.jpg'  # Replace with the path to your image
image = Image.open(image_path)
photo = ImageTk.PhotoImage(image)

window_width, window_height = 1000, 500
image = image.resize((window_width, window_height))
photo = ImageTk.PhotoImage(image)

image_label = tk.Label(app.root, image=photo)
image_label.image = photo  # Keep a reference to avoid garbage collection
image_label.place(relx=0.5, rely=0.5, anchor='center')
app.root.configure(bg='lightblue')

label1 = app.add_label("I am a Funny Guy", row=0, column=0)
label1.config(fg='red', bg='lightblue', font=custom_font)


label = app.add_label("", row=0, column=10)
label.place(relx=0.5, rely=0.5, anchor='center')
label.config(fg='black', bg='white', font=custom_font)

def on_button_click():
    global n
    result = subprocess.run(['./jokeWriter'], text=True, capture_output=True)
    
    label.config(text=result.stdout)
    
app.add_button("Jokes", command=on_button_click, row=1, column=0)


app.run()

