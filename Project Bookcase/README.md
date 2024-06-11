# Project Bookcase

The ```bookcase.cpp``` program implements a simplified simulation of a library in C++. 

Specifically:

- **Classes**: classes are created to represent the library, the shelves (external and internal to the cabinet), the cabinet, the base, and the books. Each class has its own functions and data.

- **Books**: represented by title, author, and ISBN.

- **Shelves**: Each shelf can accommodate a certain number of books (`NMax` capacity). They support the insertion and removal of books.

- **Cabinet**: Has two internal shelves with the same functions as the external shelves.

- **Base**: Has no functional role beyond initialization and destruction.

- **Functions**: Includes functions for placing and removing books on/off specific shelves or the cabinet, and for printing the library status.

- **Execution**: ```main``` handles library creation, random book generation, random book insertions and removals based on parameters given from the command line, and finally printing the final state of the library.

- **Parameters**: The program accepts as parameters from the command line

The library takes as parameters from the command line the maximum capacity of the shelves (`NMax`), the number of books (`L`), the number of random insertions (`K1`), and the number of random removals (`K2`).

### How to run it

Compile it using `g++ -o bookcase bookcase.cpp` <br>
Example execution `bookcase.exe 5 10 7 3`

Expected Output:

```bash
User@Github:~$ ./bookcase 5 10 7 3
A base is being constructed.
A shelf is being constructed.
A shelf is being constructed.
A cupboard is being constructed.
A shelf is being constructed.
A shelf is being constructed.
A shelf is being constructed.
A library is being constructed.
Placing book: Book 9
Placing book: Book 8
Placing book: Book 7
Placing book: Book 6
Placing book: Book 5
Placing book: Book 4
Placing book: Book 3
Taking book: Book 4
Error: Shelf is empty.
Taking book: Book 7
Printing top shelf of the library:
Book: Book 9, Author: Author 9, ISBN: 9
Book: Book 6, Author: Author 6, ISBN: 6
Book: Book 3, Author: Author 3, ISBN: 3
Printing middle shelf of the library:
Shelf is empty.
Printing bottom shelf of the library:
Book: Book 5, Author: Author 5, ISBN: 5
Printing the cupboard:
Printing top shelf of the cupboard:
Book: Book 8, Author: Author 8, ISBN: 8
Printing bottom shelf of the cupboard:
Shelf is empty.
A library is being destroyed.
A shelf is being destroyed.
A shelf is being destroyed.
A shelf is being destroyed.
A cupboard is being destroyed.
A shelf is being destroyed.
A shelf is being destroyed.
A base is being destroyed.
```