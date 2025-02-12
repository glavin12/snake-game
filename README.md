# Snake Game (C++)

## Introduction
The Snake Game is a classic arcade game where the player controls a snake to eat food, growing in size while avoiding collisions with the walls and itself. This project is implemented in C++ and is designed for college-level programming assignments.

## Features
- **Console-Based Game**: Simple text-based UI using ASCII characters.
- **Smooth Controls**: Move the snake using arrow keys (`WASD`).
- **Score System**: Increases based on food eaten.
- **Game Over Condition**: The game ends when the snake collides with itself or the walls.
- **Adjustable Speed**: The snake's speed increases as the game progresses.
- **Restart Option**: Allows users to replay without restarting the application.

## Requirements
To run this project, you need:
- A C++ compiler (e.g., g++, MinGW, or MSVC)
- A terminal or console that supports real-time input
- Windows

## How to Play
1. Compile and run the program.
2. Use the arrow keys (`W`, `A`, `S`, `D`)  to control the snake.
3. Eat the food (`#`) to grow longer and increase your score.
4. Avoid hitting the walls or yourself.
5. The game ends when the snake collides with itself or the wall.
6. Restart the game by following the on-screen instructions.

## Installation & Compilation
### Using g++ (Windows):
1. Open a terminal and navigate to the project folder.
2. Compile the program using:
   ```sh
   g++ -o snake_game snake_game.cpp
