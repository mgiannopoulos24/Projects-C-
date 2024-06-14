#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string username;
    std::string password;
    double balance;

public:
    Account(const std::string& username, const std::string& password, double balance);

    const std::string& getUsername() const;
    bool checkPassword(const std::string& password) const;
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);
    void displayBalance() const;
};

#endif
