# 📚 Library Management System (C Project)

A **menu-driven Library Management System in C** that allows users to add, display, search, delete, borrow, and return books.
This project helped me practice **structs, dynamic memory allocation, file handling, and sorting algorithms**.

---

## 🚀 Features

* ➕ **Add Book** – Add new books with title, author, ISBN, and year
* 📖 **Display Books** – Show all stored books in the library
* 🔍 **Search Book** – Search by title or author
* 🗑 **Delete Book** – Remove a book by ISBN
* 🔄 **Sort Books** – Sort by title or author using `qsort()`
* 📤 **Borrow Book** – Mark a book as borrowed
* 📥 **Return Book** – Mark a borrowed book as returned
* 💾 **Save/Load Data** – Automatically save and reload books from file

---

## 🛠 Technologies & Concepts

* **Language:** C
* **Concepts practiced:**

  * `struct` to represent books
  * **Dynamic memory allocation** (`malloc`, `realloc`, `free`)
  * **File I/O** for saving and loading books
  * **String handling** (`strcmp`, `strtok`, `strcpy`)
  * **Sorting** with `qsort()`
  * **Menu-driven program design**

---

## 📦 Installation & Usage

1. Clone the repo:

   ```bash
   git clone https://github.com/<your-username>/library-management-system.git
   ```
2. Compile:

   ```bash
   gcc library.c -o library
   ```
3. Run:

   ```bash
   ./library
   ```

---

## 📸 Example Run

```text
** Welcome in your Library **

1. Add Book
2. Display Books
3. Search Book
4. Delete Book
5. Sort Books
6. Borrow Book
7. Return Book
8. Save & Exit
Enter your choice: 1
Enter book title: C Programming
Enter author name: Dennis Ritchie
Enter publication year: 1978
Enter ISBN: 12345
Book added successfully!
```

---

## 📚 What I Learned

* How to **build a complete system in C**
* Working with **dynamic arrays and memory management**
* Using **file handling** to persist data
* Implementing **borrowing/returning logic** with flags (`isBorrowed`)
* How to structure a **modular and menu-driven program**

---

## 🔮 Future Improvements

* Add user authentication (e.g., librarian vs reader)
* Track due dates for borrowed books
* Save data in CSV/JSON format instead of plain text
* GUI version using C++ or Python



## 📜 License

MIT License – free to use, modify, and share.
