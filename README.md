🍽️ Restaurant Management System (C)

A console-based Restaurant Management System developed in C as part of the Final Milestone – Programming Fundamentals project.
The system integrates multiple modules into a single master application with file handling, sorting, and a clean UI.

📌 Features

✔ Unified Master Menu
✔ Menu Management (Add, View, Sort)
✔ Table Management
✔ Order Management
✔ Bill Generation
✔ File Handling (Persistent Storage)
✔ Bubble Sort Implementation
✔ Clean & Colored Console UI
✔ Modular & Structured Code

🧩 Modules Overview
1️⃣ Menu Management

Add new menu items

Display all items in tabular format

Sort items:

By ID (Ascending / Descending)

By Name (Alphabetical A–Z)

2️⃣ Table Management

Add tables with seating capacity

Display all tables

3️⃣ Order Management

Place orders using Table No and Item ID

Display all orders

4️⃣ Billing System

Generate bills based on orders

Automatically calculate total amount

Display all generated bills

💾 File Handling (Data Persistence)

The system uses binary files to ensure that data is not lost when the program exits.

Entity	File Name
Menu	menu.dat
Tables	table.dat
Orders	order.dat
Bills	bill.dat
🔹 How It Works

On program startup → data is loaded from files

On Add / Update / Delete → files are updated immediately

On restart → previous data is restored automatically

🔁 Sorting Logic

Algorithm Used: Bubble Sort

Sorting Options:

Menu Items by ID (Ascending / Descending)

Menu Items by Name (Alphabetical)

Sorting is applied before displaying records to improve readability.

🎨 User Interface

ANSI color codes for:

Headings

Success messages

Errors and warnings

Clean table-formatted output

Screen clearing for better navigation

⚠️ Data rows are intentionally kept color-free for readability and clean screenshots.

🛠️ Technologies Used

Language: C

Concepts:

Structures

Arrays

File Handling (fopen, fread, fwrite)

Sorting Algorithms

Modular Programming

▶️ How to Run
Compile
gcc restaurant_management.c -o rms

Run
./rms


⚠️ On Windows, run the executable directly after compilation.

📂 Project Structure
Restaurant-Management-System/
│
├── restaurant_management.c
├── menu.dat
├── table.dat
├── order.dat
├── bill.dat
└── README.md

📸 Screenshots (For Report / Demo)

Main Menu with all modules

Menu list (Unsorted vs Sorted)

Data persistence after restart

Bill generation output

🎓 Academic Context

This project was developed as part of the Final Milestone – Group Integration, File Handling & Sorting for Programming Fundamentals.

🤝 Contribution

All group members contributed to the same unified codebase.
Individual responsibilities are documented in the project report.

📜 License

This project is for educational purposes only.

⭐ Final Note

This project demonstrates:

Real-world data modeling

Persistent storage

Sorting algorithms

Clean and professional console UI

Feel free to fork, improve, or use it as a learning reference.
