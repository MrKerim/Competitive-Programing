import time
import threading
import os
import re
import tkinter as tk
from tkinter import ttk
import subprocess
from selenium.webdriver.common.by import By
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager


def measure_signal_strength():

    try:
        result = subprocess.run(['ping', '-c', '3', '8.8.8.8'], capture_output=True, text=True)
        if result.returncode != 0:
            return 0
        
        output = result.stdout

        # Look for the line with min/avg/max/mdev
        for line in output.splitlines():
            if "min/avg/max" in line or "rtt min/avg/max" in line:
                parts = line.split('=')[1].strip().split(' ')[0].split('/')
                avg_ping = float(parts[1])

                if avg_ping < 50:
                    return 3  # Strong
                elif avg_ping < 150:
                    return 2  # Medium
                else:
                    return 1  # Weak

        return 1  # Fallback if parsing fails
    except Exception as e:
        print("Error measuring signal strength:", e)
        return 0


def get_inputs():
    
    connection_status = -1
    #stop_signal_event = threading.Event()

    def on_continue(event=None):
        #nonlocal stop_signal_event
        #stop_signal_event.set()
        nonlocal url, code, language
        url = url_entry.get("1.0", tk.END).strip()
        code = code_text.get("1.0", tk.END).strip()
        language = language_var.get()
        #stop the thread

        root.after(100, root.destroy)

    def on_cancel():
        #nonlocal stop_signal_event
        #stop_signal_event.set()
        nonlocal url, code, language
        url = None
        code = None
        language = None
        root.after(100, root.destroy)

    def start_signal_checker():
        print("Signal checker started")
        def signal_loop():
            #while not stop_signal_event.is_set():
            try:
                strength = measure_signal_strength()
                print("Signal strength:", strength)
                update_canvas(strength)
                    # Only schedule if the root is still alive
                if root.winfo_exists():
                    root.after(5000, signal_loop)
            except tk.TclError:
                print("Window closed, stopping signal checker.")

        root.after(100, signal_loop)

        #threading.Thread(target=signal_loop, daemon=True).start()

    root = tk.Tk()
    root.title("LeetCode Pusher")
    
    font_style = ("Arial", 16)

    window_width = 600
    window_height = 520

    screen_width = root.winfo_screenwidth()
    screen_height = root.winfo_screenheight()

    position_top = int((screen_height - window_height) / 2)
    position_left = int((screen_width - window_width) / 2)

    root.geometry(f"{window_width}x{window_height}+{position_left}+{position_top}")

    img = tk.PhotoImage(file="./icon.png")
    root.iconphoto(True, img)


    connection_status_frame = tk.Frame(root)
    connection_status_frame.pack(pady=(10, 5))

    connection_status_label = tk.Label(connection_status_frame, text="Status ", font=("Arial", 20))
    connection_status_label.pack(side=tk.LEFT, padx=10)

    canvas = tk.Canvas(connection_status_frame, width=200, height=100)
    canvas.pack(side=tk.LEFT, padx=10)


    def update_canvas(connection_status):
        canvas.delete("all") 
        def draw_bottom_aligned_rectangle(canvas, x, width, height, base_y= 65, fill="blue"):
            x0 = x
            y0 = base_y - height
            x1 = x + width
            y1 = base_y
            canvas.create_rectangle(x0, y0, x1, y1, fill=fill)

        # Example usage
        bar_width = 20
        spacing = 8
        heights = [20, 35, 50]

        for i, height in enumerate(heights):
            x = i * (bar_width + spacing) + 10
            if connection_status == 0:
                draw_bottom_aligned_rectangle(canvas, x, bar_width, height, fill="red")
            elif connection_status == 1:
                draw_bottom_aligned_rectangle(canvas, x, bar_width, height, fill="orange")
            elif connection_status == 2:
                draw_bottom_aligned_rectangle(canvas, x, bar_width, height, fill="yellow")
            elif connection_status == 3:
                draw_bottom_aligned_rectangle(canvas, x, bar_width, height, fill="green")
            else:
                draw_bottom_aligned_rectangle(canvas, x, bar_width, height, fill="gray")

    update_canvas(connection_status)

    url_label = tk.Label(root, text="Link", font=("Arial", 20))
    url_label.pack(pady=(0, 5))

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
    start_signal_checker()
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
    subprocess.run(["git", "add", "."], check=True)
    subprocess.run(["git", "status"], check=True)
    subprocess.run(["git", "commit", "-m", title_content], check=True)
    subprocess.run(["git", "push", "origin", "main"], check=True)
    print("Git operations completed successfully.")
except subprocess.CalledProcessError as e:
    print(f"An error occurred during Git operations: {e}")