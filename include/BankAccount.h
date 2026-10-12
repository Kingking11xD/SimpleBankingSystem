#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountHolderName;
    int accountNumber;
    std::string pin;
    double balance;

public:
    // Constructor
    BankAccount(std::string name, int accNum, std::string pinCode, double initialBalance);

    // Getters
    int getAccountNumber() const;
    std::string getPin() const;
    
    // Core Functions
    void deposit(double amount);
    bool withdraw(double amount, std::string inputPin);
    void displayAccountInfo(std::string inputPin) const;
    
    // For saving to our text file
    std::string toCSV() const;
};

#endif