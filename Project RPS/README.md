# Rock-Paper-Scissors Game

This is a simple Rock-Paper-Scissors game implemented in C++. The game allows the player to choose between playing against the computer or against another player.

### Building the Project

1. Open a terminal or command prompt.
2. Navigate to the root directory of the project (`rock_paper_scissors`).
3. Run the following command to build the project:
```bash
make
```
This will compile the source files and generate the executable in the `build/` directory.

### Running the Game

After building the project, you can run the game using the following command:

```bash
./build/rock_paper_scissors
```
### Cleaning Up
To clean up the build files (object files and the executable), run:
```bash
make clean
```
This will remove all the object files and the executable, allowing you to start fresh if needed.

### Game Instructions
1. When you run the game, you will be prompted to choose a game mode:
- `1`: Play with the computer.
- `2`: Play with another player.
2. Follow the prompts to enter your choice:
- `0`: Rock
- `1`: Paper
- `2`: Scissors
The game will determine the winner and display the result.

### Examples
- Against the Computer:
```bash
User@Github:~$ ./build/rock_paper_scissors 
Choose game mode (1 = Play with Computer, 2 = Play with Another Player): 1
Player 1, enter your choice (0 = Rock, 1 = Paper, 2 = Scissors): 1
Player 1 chose: Paper
Player 2 chose: Scissors
Player 2 wins!
```
- Against another player:
```bash
User@Github:~$ ./build/rock_paper_scissors 
Choose game mode (1 = Play with Computer, 2 = Play with Another Player): 2
Player 1, enter your choice (0 = Rock, 1 = Paper, 2 = Scissors): 2
Player 2, enter your choice (0 = Rock, 1 = Paper, 2 = Scissors): 1
Player 1 chose: Scissors
Player 2 chose: Paper
Player 1 wins!
```


