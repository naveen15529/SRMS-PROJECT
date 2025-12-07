Overview

This project allows users to store, view, search, add, and delete student information. All data is saved in a CSV file (students.csv), enabling persistent storage across program runs.

The system uses structures, arrays, and file handling in C to organize and manage records.

🛠️ Features

Load Data Automatically from students.csv

Add New Student with name, roll, course, year, and CGPA

Display All Students in a formatted table

Search Student using roll number

Delete Student by roll number

Save & Exit (writes all records to CSV)

📂 File Structure
project/
│── students.csv       # Auto-created if missing
│── main.c             # Program source code
│── README.md          # Documentation

🚀 How to Compile and Run
Compile
gcc main.c -o student_system

Run
./student_system

📄 CSV Format

The program uses the following format in students.csv:

Name,Roll,Course,Year,CGPA


Example:

Rahul Sharma,101,B.Tech CSE,2,8.50
Ananya Verma,102,B.Sc Physics,3,9.10

📘 How It Works

On startup, the program reads all existing records from the CSV file.

Users interact using a numeric menu system.

When exiting, the program saves all current data back into the file.

🔧 Tech Stack

Language: C

Concepts Used: Structures, File Handling, Arrays, Control Flow, Menu-driven programming

✨ Future Improvements

Update/Edit student records

Sort by CGPA, Name, or Roll

Input validation

Replace CSV with database support
