// main.cpp

#include <iostream>
#include "atm.h"

int main() {
    ATM atm;
    bool running = true;

    while (running) {
        int choice;
        std::string username, password;
        double amount;

        std::cout << "\nWelcome to the ATM System\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Login\n";
        std::cout << "3. Deposit\n";
        std::cout << "4. Withdraw\n";
        std::cout << "5. Check Balance\n";
        std::cout << "6. Logout\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << "Enter initial deposit amount: ";
                std::cin >> amount;
                atm.createAccount(username, password, amount);
                break;
            case 2:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                if (atm.login(username, password)) {
                    std::cout << "Login successful." << std::endl;
                } else {
                    std::cout << "Login failed. Invalid username or password." << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                atm.deposit(amount);
                break;
            case 4:
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                atm.withdraw(amount);
                break;
            case 5:
                atm.displayBalance();
                break;
            case 6:
                atm.logout();
                std::cout << "Logged out." << std::endl;
                break;
            case 7:
                std::cout << "Exiting ATM. Goodbye!" << std::endl;
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
