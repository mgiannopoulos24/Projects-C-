#include "atm.h"
#include <iostream>
#include <fstream>

ATM::ATM() : currentAccount(nullptr) {
    // Load existing accounts from data file (simplified for demo)
    std::ifstream infile("data.txt");
    std::string username, password;
    double balance;

    while (infile >> username >> password >> balance) {
        accounts.emplace_back(username, password, balance);
    }
}

void ATM::createAccount(const std::string& username, const std::string& password, double initialDeposit) {
    accounts.emplace_back(username, password, initialDeposit);

    // Update data file (simplified for demo)
    std::ofstream outfile("data.txt", std::ios_base::app);
    outfile << username << " " << password << " " << initialDeposit << std::endl;
}

bool ATM::login(const std::string& username, const std::string& password) {
    for (auto& acc : accounts) {
        if (acc.getUsername() == username && acc.checkPassword(password)) {
            currentAccount = &acc;
            return true;
        }
    }
    return false;
}

void ATM::deposit(double amount) {
    if (currentAccount) {
        currentAccount->deposit(amount);
        std::cout << "Deposit successful." << std::endl;
    } else {
        std::cout << "Please log in first." << std::endl;
    }
}

bool ATM::withdraw(double amount) {
    if (currentAccount) {
        if (currentAccount->withdraw(amount)) {
            std::cout << "Withdrawal successful." << std::endl;
            return true;
        } else {
            std::cout << "Insufficient funds." << std::endl;
            return false;
        }
    } else {
        std::cout << "Please log in first." << std::endl;
        return false;
    }
}

void ATM::displayBalance() const {
    if (currentAccount) {
        currentAccount->displayBalance();
    } else {
        std::cout << "Please log in first." << std::endl;
    }
}

void ATM::logout() {
    currentAccount = nullptr;
}
