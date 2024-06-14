#include <iostream>
#include "account.h"

Account::Account(const std::string& username, const std::string& password, double balance)
    : username(username), password(password), balance(balance) {}

const std::string& Account::getUsername() const {
    return username;
}

bool Account::checkPassword(const std::string& password) const {
    return this->password == password;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::displayBalance() const {
    std::cout << "Current balance: $" << balance << std::endl;
}
