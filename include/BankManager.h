#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include "BankAccount.h"
#include <vector>
#include <string>

class BankManager {
private:
    std::vector<BankAccount> accounts;
    std::string dataFile;

    // Helper functions
    void loadAccounts();
    void saveAccounts() const;
    int findAccountIndex(int accNum) const;

public:
    BankManager(std::string filename);
    ~BankManager(); // Destructor saves data when program closes

    void openAccount(std::string name, int accNum, std::string pin, double initialDep);
    void depositMoney(int accNum, double amount);
    void withdrawMoney(int accNum, double amount, std::string pin);
    void checkBalance(int accNum, std::string pin) const;
};

#endif