import subprocess
from python_tkinterMini.tkinterMini import SimpleGUI

n = 0

# create the app instance
app = SimpleGUI(title="Tkinter Example", width=400, height=300)
app.add_label("This is a Joke Generator!", row=0, column=0)

app.add_label("", row=3, column=0)


def on_button_click():
    global n
    result = subprocess.run(['./jokeWriter'], text=True, capture_output=True)
    
    app.add_label(result.stdout, row=3, column=0)
    
app.add_button("Click Me", command=on_button_click, row=1, column=0)

app.run()