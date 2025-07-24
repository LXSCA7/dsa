# Data Structures & Algorithms in C

[Versão em Português](README.pt-br.md)

This repository is a personal study project to implement classic data structures and algorithms in pure C, focusing on clean, modular, and efficient code.

---

## Implemented Data Structures

- [x] **Linked List**: The foundation for other data structures.
- [x] **Stack**: Implemented on top of the Linked List (LIFO).
- [x] **Queue**: Implemented on top of the Linked List (FIFO).
- [ ] **Binary Search Tree (BST)**
- [ ] **Hash Table**

---

## How to Run

### Prerequisites
To build and run this project, you need:
- git;
- A C compiler, such as gcc or clang;
- make.

### Steps

1.  **Clone the repository:**
      ```bash
      git clone https://github.com/LXSCA7/dsa.git
      cd dsa
      ```

2.  **Build the project:**
The easiest and recommended way is to use the provided `Makefile`. In your terminal, at the project's root directory, run:
      ```bash
      make
      ```
    This will compile all source files and create the executable `main` inside a `bin/` directory.

3.  **Run the program:**
   You can use another `Makefile` rule to run the program directly:
      ```bash
      make run
      ```

### Useful makefile commands
- `make`: Builds the project.
- `make run`: Builds (if needed) and runs the project.
- `make clean`: Removes all generated files from the compilation (the `bin/` folder).
