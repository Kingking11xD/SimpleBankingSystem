#include "../include/BankManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

BankManager::BankManager(string filename) {
    dataFile = filename;
    loadAccounts();
}

BankManager::~BankManager() {
    saveAccounts(); // Ensures data is saved right before the program ends
}

void BankManager::loadAccounts() {
    ifstream file(dataFile);
    if (!file.is_open()) return; // File might not exist yet, that's fine

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string accStr, pinCode, balStr, name;

        // Parse the CSV line
        getline(ss, accStr, ',');
        getline(ss, pinCode, ',');
        getline(ss, balStr, ',');
        getline(ss, name, ',');

        if (!accStr.empty()) {
            accounts.push_back(BankAccount(name, stoi(accStr), pinCode, stod(balStr)));
        }
    }
    file.close();
}

void BankManager::saveAccounts() const {
    ofstream file(dataFile);
    for (size_t i = 0; i < accounts.size(); i++) {
        file << accounts[i].toCSV() << "\n";
    }
    file.close();
}

int BankManager::findAccountIndex(int accNum) const {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNum) {
            return i;
        }
    }
    return -1;
}

void BankManager::openAccount(string name, int accNum, string pin, double initialDep) {
    if (findAccountIndex(accNum) != -1) {
        cout << "\nError: Account number already exists!" << endl;
        return;
    }
    accounts.push_back(BankAccount(name, accNum, pin, initialDep));
    saveAccounts(); // Save immediately so data isn't lost if program crashes
    cout << "\nAccount successfully created for " << name << "!" << endl;
}

void BankManager::depositMoney(int accNum, double amount) {
    int index = findAccountIndex(accNum);
    if (index != -1) {
        accounts[index].deposit(amount);
        saveAccounts();
    } else {
        cout << "\nError: Account not found." << endl;
    }
}

void BankManager::withdrawMoney(int accNum, double amount, string pin) {
    int index = findAccountIndex(accNum);
    if (index != -1) {
        if (accounts[index].withdraw(amount, pin)) {
            saveAccounts();
        }
    } else {
        cout << "\nError: Account not found." << endl;
    }
}

void BankManager::checkBalance(int accNum, string pin) const {
    int index = findAccountIndex(accNum);
    if (index != -1) {
        accounts[index].displayAccountInfo(pin);
    } else {
        cout << "\nError: Account not found." << endl;
    }
}