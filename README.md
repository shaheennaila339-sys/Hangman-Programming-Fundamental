# Hangman-Programming-Fundamental
# 🎮 Hangman Game in C
A classic terminal-based word guessing game developed in C, featuring dynamic logic and structured data management.

---

## 📌 Project Overview
This project is a functional implementation of the Hangman game. It challenges the player to guess a hidden word from a selected category within a limited number of attempts. It was built as part of the Programming Fundamentals course to demonstrate core C concepts.

## 🚀 Key Features
* **Category Selection:** Choose between Fruits, Colors, and Vegetables.
* **Randomized Logic:** Every game session pulls a random word using time-seeded randomization.
* **Case-Insensitivity:** Handles both uppercase and lowercase inputs seamlessly.
* **Dynamic Difficulty:** The number of attempts is automatically calculated based on the word's length.
* **Clean UI:** Uses simple terminal formatting for a better user experience.

## 🛠️ Technical Concepts Used
This project utilizes several advanced C programming techniques:
* **Structures (`struct`):** To bundle game data (word, guessed letters, attempts) into a single entity.
* **Custom Data Types:** Using `typedef` for cleaner and more readable code.
* **String Manipulation:** Functions like `strncpy`, `strlen`, and `strcmp` for handling game logic.
* **Modular Programming:** Logic is divided into functions (`initializeGame`, `processGuess`, etc.) for better maintainability.
* **Memory Management:** Efficient use of character arrays and buffers.

## 💻 How to Run

### Prerequisites
You need a C compiler (like GCC) installed on your system.

### 1. Compile the Code
Open your terminal and run:
```bash
gcc hangman.c -o hangman
