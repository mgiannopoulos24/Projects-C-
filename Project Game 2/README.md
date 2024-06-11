# Project Vampires vs Werewolves

## Introduction
This project consists of a console-based game implemented in C++, where the player controls an avatar trying to avoid vampires and werewolves while collecting potions. The game is played on a grid-based terrain.

## Files
1. main.cpp: Main C++ file containing the game logic and the main function.
2. terrain.h: Header file containing the definition of the `Terrain` class used to represent the grid cells.
3. beings.h: Header file containing the definition of various classes representing beings in the game, including monsters, vampires, werewolves, the avatar controlled by the player, and potions.
4. beings.cpp: Implementation of the classes defined in `beings.h`.
5. terrain.cpp: Implementation of the `Terrain` class defined in `terrain.h`.

## How to Play
- The objective of the game is to avoid colliding with vampires and werewolves while collecting potions.
- Use the following controls to move the avatar:
    - W: Move up
    - S: Move down
    - A: Move left
    - D: Move right

## Compilation and Execution

Compile with: `g++ main.cpp beings.cpp terrain.cpp -o game`

Run with: `./game`

## Game map

```bash
. . . . . . . . . .
. V . W . . . . . .
. . . W . . . . . .
. . . . . . . . . .
W . . . . . . . . V
. . . . . . V . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . A . P .
. . . . . . . . . .
```


## Note
- The game grid size is currently set to 10x10 but can be adjusted by changing the values of n and m in the main function.
- Random values are generated for attributes such as health, attack, defense, and medicine within specified ranges for vampires and werewolves.
- The game utilizes the srand function with the current time as the seed for generating random numbers.
- For Windows, input is handled using _kbhit() and _getch(), while for Linux, the ncurses library is used for input handling.

## Enjoy the Game!
Have fun playing the game and feel free to modify and expand upon the code to add more features and challenges!

## Special Thanks

Special thanks to [piroar](https://github.com/piroar) for the original implementation.