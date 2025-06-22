# CLI Contact Book (C++)

A simple command-line Contact Management System built using C++. Supports file persistence, search, edit, and delete features. Data is stored in plain text format.

## Features
- Add, view, search, edit, and delete contacts
- Search by name or phone (case-insensitive)
- File-based persistence using `.txt`
- Input validation and modular structure

## Tech Used
- C++ (Standard Library)
- File I/O (`fstream`)
- Struct-based model
- Header and source file separation

## How to Run
```bash
g++ main.cpp utils.cpp Validator.cpp -o ContactBook
./ContactBook
```
### Option 2: Run Precompiled `.exe`
> Download the `contactBook.exe ` (Optional: `ContactList.txt` for sample data in same directory)  
> Then double-click or run via terminal:
```bash
./ContactBook.exe

