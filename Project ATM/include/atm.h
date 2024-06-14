#ifndef ATM_H
#define ATM_H

#include <vector>
#include "account.h"

class ATM {
private:
    std::vector<Account> accounts;
    Account* currentAccount;

public:
    ATM();

    void createAccount(const std::string& username, const std::string& password, double initialDeposit);
    bool login(const std::string& username, const std::string& password);
    void deposit(double amount);
    bool withdraw(double amount);
    void displayBalance() const;
    void logout();
};

#endif
