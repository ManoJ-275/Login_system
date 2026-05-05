# Login & Registration System in C++

A simple Login and Registration System in C++ with file-based storage.

## What it does
- Register with username and password
- Password confirmation on registration
- Checks for duplicate usernames
- Login with saved credentials
- Data saved to file and persists after program closes

## How to Run

**Compile:**
```bash
g++ -o login login_system.cpp
```

**Run:**
```bash
./login
```

## How it Works
1. Register → checks duplicate → confirms password → saves to file
2. Login → reads file → matches username and password

## What I Learned
- File handling in C++ (fstream)
- Reading and writing to files
- String comparison
- Basic authentication logic

## Technologies Used
- C++
- File I/O (fstream)
