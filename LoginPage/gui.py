import tkinter as tk
import subprocess

def register_user():
    username = username_entry.get()
    password = password_entry.get()
    result = subprocess.run(['./main', '1', username, password], capture_output=True, text=True)
    output_text.insert(tk.END, result.stdout)

def login_user():
    username = username_entry.get()
    password = password_entry.get()
    result = subprocess.run(['./main', '2', username, password], capture_output=True, text=True)
    output_text.insert(tk.END, result.stdout)

# GUI setup
root = tk.Tk()
root.title("User Authentication")

# Username input
tk.Label(root, text="Username:").pack()
username_entry = tk.Entry(root)
username_entry.pack()

# Password input
tk.Label(root, text="Password:").pack()
password_entry = tk.Entry(root, show="*")
password_entry.pack()

# Buttons for register and login
register_button = tk.Button(root, text="Register", command=register_user)
register_button.pack()
login_button = tk.Button(root, text="Login", command=login_user)
login_button.pack()

# Output text area
output_text = tk.Text(root, height=10, width=50)
output_text.pack()

root.mainloop()
