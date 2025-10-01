# TicTacToe Game

## Overview
This is a console-based Tic Tac Toe game written in C. The game provides two modes:
1. Player vs Player - Two human players can play against each other
2. Player vs Computer - Play against an AI opponent

## Project Structure
- `TicTacToe.c` - Main game source code
- `tictactoe` - Compiled executable (generated from source)
- `.gitignore` - Git ignore file for C build artifacts

## Build System
The project uses Clang C compiler:
```bash
clang -o tictactoe TicTacToe.c
```

## Running the Game
The game runs in the console and is configured to start automatically via the TicTacToe Game workflow.

To manually compile and run:
```bash
clang -o tictactoe TicTacToe.c
./tictactoe
```

## Game Features
- Interactive text-based user interface
- Smart AI opponent that can block and win
- Cross-platform support (Linux, Windows, macOS)
- Clean terminal display with board visualization

## Recent Changes
- **2025-10-01**: Initial setup in Replit environment
  - Installed C compiler toolchain (clang)
  - Compiled the game successfully
  - Created workflow for console-based execution
  - Added .gitignore for C build artifacts
  - Created project documentation

## Project Architecture
- **Language**: C
- **Compiler**: Clang 14
- **Output**: Console/Terminal (TUI)
- **Dependencies**: Standard C library only (stdio.h, stdlib.h, ctype.h, unistd.h)
