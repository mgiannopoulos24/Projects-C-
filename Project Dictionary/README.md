# Dictionary Application
This project is a simple command-line dictionary application implemented in C++. It allows users to manage a dictionary where words and their definitions are stored persistently in a text file (`Dictionary.txt`).

## Features
- Add Word: Add a new word along with its definition to the dictionary.
- Remove Word: Remove a word and its definition from the dictionary.
- Search Word: Search for a word in the dictionary and display its definition.
- List All Words: Display all words and their definitions currently in the dictionary.
- Persistent Storage: Words and their definitions are stored in a text file (Dictionary.txt) and loaded into memory when the application starts.

## Compilation
To compile the project, navigate to the root directory containing the Makefile and execute the following command:
```bash
make
```

This command will compile the source files (`Dictionary.cpp` and `main.cpp`), generate object files in the `obj` directory, and create an executable `dictionary_app` in the `build` directory.

## Usage
After compiling, run the executable dictionary_app from the build directory:

```bash
./build/dictionary_app
```

## Menu Options
1. Add word: Enter a word and its definition to add to the dictionary.
2. Remove word: Enter a word to remove it from the dictionary.
3. Search word: Enter a word to search for its definition in the dictionary.
4. List all words: Display all words currently in the dictionary along with their definitions.
5. Exit: Exit the dictionary application.
## Notes
- The dictionary data is saved automatically to `Dictionary.txt` whenever a word is added or removed.
- Ensure that the `Dictionary.txt` file has appropriate read/write permissions for the application to function correctly.
- Modify the `Dictionary.txt` file directly with caution as it may affect the application's behavior.