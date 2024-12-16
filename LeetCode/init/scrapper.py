import time
import os
import re
import tkinter as tk
from tkinter import ttk
import subprocess
from selenium.webdriver.common.by import By
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

def get_inputs():
    def on_continue(event=None):
        nonlocal url, code, language
        url = url_entry.get("1.0", tk.END).strip()
        code = code_text.get("1.0", tk.END).strip()
        language = language_var.get()
        root.destroy()

    def on_cancel():
        nonlocal url, code, language
        url = None
        code = None
        language = None
        root.destroy()
        exit()

    root = tk.Tk()
    root.title("LeetCode Pusher")
    
    font_style = ("Arial", 16)

    window_width = 600
    window_height = 400

    screen_width = root.winfo_screenwidth()
    screen_height = root.winfo_screenheight()

    position_top = int((screen_height - window_height) / 2)
    position_left = int((screen_width - window_width) / 2)

    root.geometry(f"{window_width}x{window_height}+{position_left}+{position_top}")

    img = tk.PhotoImage(file="./icon.png")
    root.iconphoto(True, img)

    url_label = tk.Label(root, text="Link", font=("Arial", 20))
    url_label.pack(pady=(10, 5))

    url_entry = tk.Text(root, height=2, width=80, font=font_style)
    url_entry.pack(pady=(0, 10))

    code_frame = tk.Frame(root)
    code_frame.pack(pady=(10, 5))

    code_label = tk.Label(code_frame, text="Code:", font=("Arial", 20))
    code_label.pack(side=tk.LEFT, padx=10)

    language_var = tk.StringVar(value="cpp")
    language_dropdown = ttk.Combobox(code_frame, textvariable=language_var, values=["cpp", "py", "js"], font=font_style)
    language_dropdown.pack(side=tk.LEFT, padx=10)

    code_text = tk.Text(root, height=10, width=80, font=font_style)
    code_text.pack(pady=(0, 10))

    button_frame = tk.Frame(root)
    button_frame.pack(pady=10)

    continue_button = tk.Button(button_frame, text="Continue", command=on_continue)
    continue_button.pack(side=tk.LEFT, padx=10)

    cancel_button = tk.Button(button_frame, text="Cancel", command=on_cancel)
    cancel_button.pack(side=tk.LEFT, padx=10)

    root.bind('<Return>', on_continue)

    url = None
    code = None
    language = None

    root.mainloop()

    return url, code, language


url, code, language = get_inputs()

if url == "" :
    print("Canceling..")
    exit()


driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()))


driver.get(url)
meta_description = driver.find_element(By.XPATH, '//meta[@name="description"]')
meta_title = driver.find_element(By.XPATH,'//meta[@property="og:title"]')
description_content = meta_description.get_attribute('content')
title_content = meta_title.get_attribute('content')

driver.quit()

extension = language 

print("title : ",title_content)


current_folder = os.path.dirname(os.path.abspath(__file__))
parent_folder = os.path.abspath(os.path.join(current_folder, ".."))

folders = [f for f in os.listdir(parent_folder) if os.path.isdir(os.path.join(parent_folder, f))]


if title_content in folders:
    target_folder = os.path.join(parent_folder, title_content)
else:

    target_folder = os.path.join(parent_folder, title_content)
    os.mkdir(target_folder)

solution_file = os.path.join(target_folder, f"solution.{extension}")


with open(solution_file, "w") as file:
    file.write(code)

print("Solution file created")

def transform_description(description):
    pattern = r"\[(https?:[^\]]+)\]"
    def replacer(match):
        url = match.group(1)
        return f"\n<p align=\"center\">\n  <img src=\"{url}\" alt=\"image\" >\n</p>\n"
    return re.sub(pattern, replacer, description)


markdown_file = os.path.join(target_folder, "README.md")
with open(markdown_file, "w") as file:
    file.write(f"# {title_content}\n[See the question in LeetCode]({url})\n\n{transform_description(description_content)}\n")

print("Readme file created ")

print("Pushing to the repo..")
try:
    os.chdir(parent_folder)
    subprocess.run(["git", "status"], check=True)
    #subprocess.run(["git", "add", "."], check=True)
    #subprocess.run(["git", "commit", "-m", title_content], check=True)
    #subprocess.run(["git", "push", "origin", "main"], check=True)
    print("Git operations completed successfully.")
except subprocess.CalledProcessError as e:
    print(f"An error occurred during Git operations: {e}")