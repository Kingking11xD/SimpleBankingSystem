#include "../include/BankAccount.h"
#include <iostream>
#include <sstream>

using namespace std;

BankAccount::BankAccount(string name, int accNum, string pinCode, double initialBalance) {
    accountHolderName = name;
    accountNumber = accNum;
    pin = pinCode;
    balance = initialBalance;
}

int BankAccount::getAccountNumber() const { return accountNumber; }
string BankAccount::getPin() const { return pin; }

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "\nSuccess! Deposited $" << amount << "\nNew Balance: $" << balance << endl;
    } else {
        cout << "\nInvalid deposit amount." << endl;
    }
}

bool BankAccount::withdraw(double amount, string inputPin) {
    if (inputPin != pin) {
        cout << "\nAccess Denied: Incorrect PIN." << endl;
        return false;
    }
    
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "\nSuccess! Withdrew $" << amount << "\nNew Balance: $" << balance << endl;
        return true;
    } else {
        cout << "\nTransaction Failed: Insufficient funds or invalid amount." << endl;
        return false;
    }
}

void BankAccount::displayAccountInfo(string inputPin) const {
    if (inputPin != pin) {
        cout << "\nAccess Denied: Incorrect PIN." << endl;
        return;
    }
    cout << "\n--- Account Details ---" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder: " << accountHolderName << endl;
    cout << "Current Balance: $" << balance << endl;
    cout << "-----------------------" << endl;
}

string BankAccount::toCSV() const {
    // Format: AccountNumber,PIN,Balance,AccountHolderName
    stringstream ss;
    ss << accountNumber << "," << pin << "," << balance << "," << accountHolderName;
    return ss.str();
}