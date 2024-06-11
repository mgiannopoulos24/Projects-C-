# Project Bank

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

Expected Output:

```bash
User@Github:~$ ./bank 2 3 6 4
Customer 1 entered.
Cashier opened.
Customer 2 entered.
Customer 3 entered.
Cashier opened.
Customer 4 entered.
Customer 5 entered.
Cashier opened.
Customer 6 entered.
Customer served.
Customer no: 1 served by cashier no: 1
Customer served.
Customer no: 2 served by cashier no: 2
Cashier closed.
Customer served.
Customer no: 3 served by cashier no: 3
Customer served.
Customer no: 4 served by cashier no: 2
Cashier closed.
Customer served.
Customer no: 5 served by cashier no: 3
Customer served.
Customer no: 6 served by cashier no: 3
Cashier closed.
Customer 7 entered.
Cashier opened.
Customer 8 entered.
Customer 9 entered.
Cashier opened.
Customer 10 entered.
Customer 11 entered.
Cashier opened.
Customer 12 entered.
Customer served.
Customer no: 7 served by cashier no: 1
Customer served.
Customer no: 8 served by cashier no: 2
Cashier closed.
Customer served.
Customer no: 9 served by cashier no: 3
Customer served.
Customer no: 10 served by cashier no: 2
Cashier closed.
Customer served.
Customer no: 11 served by cashier no: 3
Customer served.
Customer no: 12 served by cashier no: 3
Cashier closed.
Customer 13 entered.
Cashier opened.
Customer 14 entered.
Customer 15 entered.
Cashier opened.
Customer 16 entered.
Customer 17 entered.
Cashier opened.
Customer 18 entered.
Customer served.
Customer no: 13 served by cashier no: 1
Customer served.
Customer no: 14 served by cashier no: 2
Cashier closed.
Customer served.
Customer no: 15 served by cashier no: 3
Customer served.
Customer no: 16 served by cashier no: 2
Cashier closed.
Customer served.
Customer no: 17 served by cashier no: 3
Customer served.
Customer no: 18 served by cashier no: 3
Cashier closed.
Waiting customers: 0
Open cashiers: 0
```