# ATM Management System
The ATM Management System is a console-based application written in C++ that simulates basic functionalities of an Automated Teller Machine (ATM). It allows users to create accounts, log in, deposit and withdraw funds, check balances, and perform other banking operations.


## How to compile

To compile use `make` or `make all` and to remove it use `make clean`.


## Usage
Upon running the application (`./atm`), you will be presented with a menu with options such as:

1. Create Account
2. Login
3. Deposit
4. Withdraw
5. Check Balance
6. Logout
7. Exit

Follow the on-screen prompts to navigate through the options and perform the desired operations.

## Example Execution

1. Create Account

When choosing the first option a `data.txt` will be created that will list the name, the password and the initial deposit.
```bash
Welcome to the ATM System
1. Create Account
2. Login
3. Deposit
4. Withdraw
5. Check Balance
6. Logout
7. Exit
Enter your choice: 1
Enter username: nick
Enter password: 123
Enter initial deposit amount: 1000
```
2. Login
```bash
Welcome to the ATM System
1. Create Account
2. Login
3. Deposit
4. Withdraw
5. Check Balance
6. Logout
7. Exit
Enter your choice: 2
Enter username: nick
Enter password: 123
Login successful.
```
3. Deposit
```bash
Welcome to the ATM System
1. Create Account
2. Login
3. Deposit
4. Withdraw
5. Check Balance
6. Logout
7. Exit
Enter your choice: 3
Enter deposit amount: 1
Deposit successful.
```
4. Withdraw
```bash
Welcome to the ATM System
1. Create Account
2. Login
3. Deposit
4. Withdraw
5. Check Balance
6. Logout
7. Exit
Enter your choice: 4
Enter withdrawal amount: 1001
Withdrawal successful.
```
5. Check Balance
```bash
Welcome to the ATM System
1. Create Account
2. Login
3. Deposit
4. Withdraw
5. Check Balance
6. Logout
7. Exit
Enter your choice: 5
Current balance: $0
```
6. Logout
```bash
Welcome to the ATM System
1. Create Account
2. Login
3. Deposit
4. Withdraw
5. Check Balance
6. Logout
7. Exit
Enter your choice: 6
Logged out.
```
7. Exit
```bash
Welcome to the ATM System
1. Create Account
2. Login
3. Deposit
4. Withdraw
5. Check Balance
6. Logout
7. Exit
Enter your choice: 7
Exiting ATM. Goodbye!
```