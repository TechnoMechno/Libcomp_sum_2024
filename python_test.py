import subprocess
from python_tkinterMini.tkinterMini import SimpleGUI

n = 0

# create the app instance
app = SimpleGUI(title="Tkinter Example", width=1000, height=500)
app.add_label("I am a Funny Guy", row=0, column=0)

label = app.add_label("", row=0, column=10)


def on_button_click():
    global n
    result = subprocess.run(['./jokeWriter'], text=True, capture_output=True)
    
    label.config(text=result.stdout)
    
app.add_button("Jokes", command=on_button_click, row=1, column=0)

app.run()