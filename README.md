# 🎮 Tic-Tac-Toe Game in C  

## 📌 Overview  
This is a **Tic Tac Toe game** implemented in **C language**, playable directly in the terminal.  
It supports:  
- 👥 **Player vs Player mode** - Two human players can play against each other
- 🤖 **Player vs Computer mode** - Play against an AI opponent 

The game runs smoothly on **Windows**, **Linux**, and **macOS**.  
It uses the console/terminal for the game board, with clear visuals and interactive gameplay.  

---

## ✨ Features  
- Clean & interactive game board (auto-refreshes each turn)  
- **Two modes** – Player vs Player & Player vs Computer  
- AI computer move selection (blocking & winning strategy)  
- Works on both Windows & Linux (with `cls` or `clear` screen handling)  
- Detects **win, lose, or draw** with clear messages  

---

## 📂 Project Structure 
```
├── tic_tac_toe.c # Main C source file (game logic)
|__ README.md # Documentation
```

---

## ⚡ How to Run  

- Clone the repository:  
   ```bash
   git clone https://github.com/your-username/tic-tac-toe-c.git
   cd tic-tac-toe-c
   ```
### 🔹 On Linux / macOS  
  - Compile and Run the program:
```bash
gcc tic_tac_toe.c -o tic_tac_toe
./tic_tac_toe
```
### 🔹 On Windows (Visual Studio)

- Open Command Prompt or terminal where the file is saved.
- Compile and Run the game:
```bash
  gcc tic_tac_toe.c -o tic_tac_toe.exe
  tic_tac_toe.exe
```
---
## 🎮 Gameplay Instructions
Choose game mode:
- 1 → Player vs Player
- 2 → Computer vs Player
- 3 → Exit

Players select a square (1–9) to place their mark:
- X → Player 1 / Computer
- O → Player 2 / Human

Game ends when:
- A player gets 3 in a row → Win
- All squares are filled → Draw
---
## Game Features
- Interactive text-based user interface
- Smart AI opponent that can block and win
- Cross-platform support (Linux, Windows, macOS)
- Clean terminal display with board visualization
---
## 🛠️ Requirements
- GCC Compiler (gcc) or any standard C compiler
- Works on Windows, Linux, macOS
