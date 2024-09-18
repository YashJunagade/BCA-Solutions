import tkinter as tk

def create_course_list():
    # List of Computer Science courses
    courses = [
        "Introduction to Programming",
        "Data Structures and Algorithms",
        "Computer Networks",
        "Operating Systems",
        "Database Systems",
        "Software Engineering",
        "Artificial Intelligence",
        "Machine Learning",
        "Computer Graphics",
        "Cybersecurity"
    ]
    
    # Populate the Listbox with courses
    for course in courses:
        listbox.insert(tk.END, course)

# Set up the main window
root = tk.Tk()
root.title("Computer Science Courses")

# Create and place the Listbox widget
listbox = tk.Listbox(root, width=50, height=10)
listbox.pack(pady=20)

# Create and populate the course list
create_course_list()

# Run the application
root.mainloop()
