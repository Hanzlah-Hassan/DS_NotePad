
Console-Based Notepad Application with Spell-Checking and Dictionary Support
Overview:
This project implements a console-based notepad application with advanced features such as spell-checking, text manipulation, and file handling. The application uses an AVL Tree for efficient dictionary lookups and supports various text editing functionalities.

Features:s
Core Features
AVL Tree Dictionary: Efficiently stores and searches dictionary words.
Spell-Checking: Automatically checks the spelling of words upon completion.
Dynamic Editing: Letters are stored in a linked list, allowing easy insertion and deletion.
File Operations:
Load text from a file (Ctrl + L).
Save current text to a file (Ctrl + S).
Spell-Check Enhancements
Suggest corrections using:
Letter substitution
Letter omission
Letter insertion
Adjacent letter reversal
Text Manipulation
Add/Delete text dynamically.
Use backspace to delete the last typed character.
Keyboard Shortcuts
Key	Function
Ctrl + L	Load text from a file.
Ctrl + S	Save current text.
Backspace	Delete last character.
Esc	Exit the application.
System Architecture
Data Structures
AVL Tree:
Used for dictionary storage and lookup.
Ensures balanced structure for efficient operations.
Linked List:
Stores user input dynamically.
Stack/Queue:
Tracks the current word for spell-checking.
Spell-Check Logic
Word Formation:

Letters typed are tracked using a stack or queue.
Upon pressing Space, the word is spell-checked.
Correction Techniques:

Substitution: Replace a letter in the word to form valid words.
Omission: Remove a letter to form valid words.
Insertion: Add a letter to the word at various positions.
Reversal: Swap adjacent characters in the word.
Dictionary Matching:

Checks the word in the AVL Tree for validity.
Suggests corrections if the word is invalid.
Installation
Prerequisites
C++ compiler (e.g., GCC).
ncurses library for terminal-based UI.
Steps to Compile and Run
Clone the repository:
bash
Copy code
git clone https://github.com/Hanzlah-Hassan/DS_NotePad.git
Compile the program:
bash
Copy code
g++ -o notepad *.cpp -lncurses
Run the application:
bash
Copy code:
./notepad
Usage Instructions
Starting the Application
Launch the application and start typing.
The typed text will dynamically appear in the notepad.
File Operations
Press Ctrl + L to load a file into the notepad.
Press Ctrl + S to save the current text to save.txt.
Exiting
Press Esc to exit and free all memory.
File Structure
bash
Copy code
.
├── dictionary.txt      # Word list for the AVL tree dictionary
├── notepad.cpp         # Main program file
├── Queue.h             # Queue implementation for word tracking
├── colorPair.h         # Color management for ncurses
└── README.md           # Project documentation
Authors
Hanzlah Hassan
BS Artificial Intelligence, FAST University, Pakistan
