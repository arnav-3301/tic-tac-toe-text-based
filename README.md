# Tic-Tac-Toe (C++ / Terminal)

A lightweight, terminal-based implementation of Tic-Tac-Toe written in C++. This project focuses on efficient state management, robust input sanitization, and a clean command-line interface.

## Description

This application provides a two-player local experience within the terminal. Key features include:
* **Input Sanitization:** Prevents crashes or logic errors from non-integer inputs (e.g., character strings) and out-of-bounds moves.
* **State Machine:** Efficiently evaluates win conditions (horizontal, vertical, diagonal) and draw states after every move.
* **Low Overhead:** Minimalist C++ code designed for high-speed execution and low memory footprint.
* **Session Control:** Integrated interrupt handling via specific key commands to end the game gracefully.

## Installation

### Prerequisites
* A C++ compiler (G++ or Clang++).
* CMake (optional, for IDE users).

### Building from Source
1. **Clone the repository:**
   ```bash
   git clone git@github.com:arnav-3301/tic-tac-toe-text-based.git
   cd tic-tac-toe-text-based
   ```

2. **Compile using G++:**
   ```bash
   g++ main.cpp -o tic_tac_toe
   ```

3. **Run the executable:**
   ```bash
   ./tic_tac_toe
   ```

## How to Play

### Grid Mapping
The board uses a numeric 1-9 mapping corresponding to the following indices:

```text
 1 | 2 | 3 
---|---|---
 4 | 5 | 6 
---|---|---
 7 | 8 | 9 
```

### Controls
* **Select Cell:** Type the number (1-9) of an empty cell and press `Enter`.
* **Alternate Turns:** The game starts with **X** and automatically switches to **O**.
* **Quit Game:** Type `q` at any prompt to terminate the session immediately.

### Game End
* **Win:** Occurs when a player aligns three marks horizontally, vertically, or diagonally.
* **Draw:** Occurs when all cells are filled without a three-mark alignment.

---

### Technical Note for CLion Users
This project is fully compatible with CMake. You can open the directory in CLion, and it will automatically generate the build targets. The compiled binary will typically be located in the `cmake-build-debug` directory.
