# Projects-CPP
C++ projects | Object Oriented Programming

## Project Bookcase

The ```bookcase.cpp``` program implements a simplified simulation of a library in C++. Specifically:

- **Classes**: classes are created to represent the library, the shelves (external and internal to the cabinet), the cabinet, the base, and the books. Each class has its own functions and data.

- **Books**: represented by title, author, and ISBN.

- **Shelves**: Each shelf can accommodate a certain number of books (`NMax` capacity). They support the insertion and removal of books.

- **Cabinet**: Has two internal shelves with the same functions as the external shelves.

- **Base**: Has no functional role beyond initialization and destruction.

- **Functions**: Includes functions for placing and removing books on/off specific shelves or the cabinet, and for printing the library status.

- **Execution**: ```main``` handles library creation, random book generation, random book insertions and removals based on parameters given from the command line, and finally printing the final state of the library.

- **Parameters**: The program accepts as parameters from the command line

The library takes as parameters from the command line the maximum capacity of the shelves (`NMax`), the number of books (`L`), the number of random insertions (`K1`), and the number of random removals (`K2`).

