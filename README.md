# Library Management System in C


A **console-based library management system** written in C that allows users to manage books: adding, deleting, searching, sorting, borrowing, and returning them. It also supports persistent storage with a file.


## 📝 Features

*  **Add Book** – Input book title, author, publication year, and ISBN.
*  **Display Books** – View all books in your library.
*  **Search Book** – Search books by title or author.
*  **Delete Book** – Remove a book by its ISBN.
*  **Sort Books** – Sort books alphabetically by title or author.
*  **Borrow & Return** – Track borrowed books.
*  **Persistent Storage** – Save/load library data to/from `library.txt`.

---

## 💻 Technologies Used

* **Language:** C
* **Compiler:** GCC / Clang / Visual Studio
* **OS:** Windows (fully compatible; partially portable to Linux/Mac)

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/M-Chlihi/library-management-c.git
cd library-management-c
```

### 2. Compile the Program

```bash
gcc main.c -o library.exe
```

### 3. Run the Program

```bash
./library.exe   # Linux/Mac
library.exe     # Windows
```

---

## 📂 File Storage

* Books are stored in `library.txt` with the format:

```
Title;Author;ISBN;Year
```

* Data is automatically loaded at startup if the file exists.
* Changes are saved when selecting **Save & Exit**.

---

## ⚙️ Functions Overview

* `addBook()` – Add a book.
* `displayBooks()` – Show all books.
* `searchBook()` – Search by title/author.
* `deleteBook()` – Delete by ISBN.
* `sortBooks()` – Sort books alphabetically.
* `borrowBook()` / `returnBook()` – Borrow and return books.
* `saveToFile()` / `loadFromFile()` – Save/load library data.
* Utility: `trim()`, `toUpperCase()`, `compareByTitle()`, `compareByAuthor()`.

---

## 🔍 Screenshots

**Library Menu:**

```
** Welcome in your Library **

1. Add Book
2. Display Books
3. Search Book
4. Delete Book
5. Sort Books
6. Borrow Book
7. Return Book
8. Save & Exit
Enter your choice:
```

**Displaying Books:**

```
📚 Library Collection (3 books):
--------------------------------------
Book #1
Title: C Programming
Author: Dennis Ritchie
Year: 1978
ISBN: 1234567890
--------------------------------------
```

---

## 📌 Notes

* ISBN serves as a unique identifier.
* Dynamic memory allocation allows flexible library size.
* Borrowed books are tracked with a boolean flag.

---

## 📜 License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).

---
