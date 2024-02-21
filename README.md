# Projects-CPP
C++ projects | Object Oriented Programming

## Project Bookcase

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

## Project Bank

The ```bank.cpp``` program implements creates a simplified simulation for customer and fund management in a bank in C++.

Specifically:

- **Creating a bank and cashiers**: Τhe program starts by initializing abank containing several cashiers. Each cashier has a customer service limit(`L`), after which it is closed due to overload.

- **Customer introduction**: Customers enter the bank via the `enter` method. If the number of customers exceeds the capacity of the available funds, new customers are not allowed to enter.

- **Customer service**: The `serve` method serves customers one by one. A cashier is selected to serve each customer, based on the opening status of the cashiers and the current order of service.

- **Cashier management (Open/Close)**: Τhe `checkToOpen` and `checkToClose` methods check respectively whether to open or close cashiers, based on the number of customers waiting for service.

- **Status monitoring**: The `status` method provides an overview of the number of customers waiting and the number of counters open.

- **Parameters**: The program accepts as parameters from the command line

The bank takes as parameters from the command line the maximum number of customers per checkout before service (`K`), the customer service limit for each cashier (`L`), the number of rounds for customer introduction (`M`), the number of customers entering each round (`N`).

### How to run it

Compile it using `g++ -o bank bank.cpp` <br>
Example execution `bank.exe 2 3 6 4`