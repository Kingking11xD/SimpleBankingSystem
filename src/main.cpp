#include <iostream>
#include <string>
#include "../include/BankManager.h"

using namespace std;

int main() {
    // Initialize the bank and load data from the file
    BankManager bank("data/accounts.txt");
    int choice;

    cout << "====================================\n";
    cout << "    SECURE C++ BANKING SYSTEM\n";
    cout << "====================================\n";

    do {
        cout << "\n1. Open a New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Account Balance / Info\n";
        cout << "5. Exit System\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, pin;
            int accNum;
            double initialDep;

            cout << "\nEnter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter a New Account Number (e.g., 1001): ";
            cin >> accNum;
            cout << "Create a PIN code: ";
            cin >> pin;
            cout << "Enter Initial Deposit Amount: $";
            cin >> initialDep;

            bank.openAccount(name, accNum, pin, initialDep);

        } else if (choice == 2) {
            int accNum;
            double amount;
            cout << "\nEnter Account Number: ";
            cin >> accNum;
            cout << "Enter deposit amount: $";
            cin >> amount;
            bank.depositMoney(accNum, amount);

        } else if (choice == 3) {
            int accNum;
            string pin;
            double amount;
            cout << "\nEnter Account Number: ";
            cin >> accNum;
            cout << "Enter your PIN: ";
            cin >> pin;
            cout << "Enter withdrawal amount: $";
            cin >> amount;
            bank.withdrawMoney(accNum, amount, pin);

        } else if (choice == 4) {
            int accNum;
            string pin;
            cout << "\nEnter Account Number: ";
            cin >> accNum;
            cout << "Enter your PIN: ";
            cin >> pin;
            bank.checkBalance(accNum, pin);

        } else if (choice == 5) {
            cout << "\nSaving data... Thank you for using Secure C++ Bank. Goodbye!\n";
        } else {
            cout << "\nInvalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}