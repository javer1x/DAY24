#include <iostream>
#include <string>
using namespace std;
const int MAX_ACCOUNTS = 100;
void createAccount(string accountNumbers[], string names[], double balances[], int& numAccounts);
void depositMoney(string accountNumbers[], double balances[], int numAccounts);
void withdrawMoney(string accountNumbers[], double balances[], int numAccounts);
void checkBalance(string accountNumbers[], double balances[], int numAccounts);
int findAccountIndex(string accountNumbers[], int numAccounts, string accountNumber);
int main() {
    string accountNumbers[MAX_ACCOUNTS];
    string names[MAX_ACCOUNTS];
    double balances[MAX_ACCOUNTS] = {0.0};
    int numAccounts = 0;
    int choice;
    string accountNumber;
    while (true) {
        cout << "Banking System Menu:" << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Check balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  
        if (choice == 1) {
            createAccount(accountNumbers, names, balances, numAccounts);
        } else if (choice == 2) {
            depositMoney(accountNumbers, balances, numAccounts);
        } else if (choice == 3) {
            withdrawMoney(accountNumbers, balances, numAccounts);
        } else if (choice == 4) {
            checkBalance(accountNumbers, balances, numAccounts);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
void createAccount(string accountNumbers[], string names[], double balances[], int& numAccounts) {
    if (numAccounts >= MAX_ACCOUNTS) {
        cout << "Account limit reached. Cannot create more accounts." << endl;
        return;
    }
    cout << "Enter account number: ";
    getline(cin, accountNumbers[numAccounts]);
    cout << "Enter account holder's name: ";
    getline(cin, names[numAccounts]);
    cout << "Enter initial balance: ";
    cin >> balances[numAccounts];
    cin.ignore();  
    numAccounts++;
    cout << "Account created successfully!" << endl;
}
void depositMoney(string accountNumbers[], double balances[], int numAccounts) {
    cout << "Enter account number for deposit: ";
    string accountNumber;
    getline(cin, accountNumber);
    int index = findAccountIndex(accountNumbers, numAccounts, accountNumber);
    if (index == -1) {
        cout << "Account not found." << endl;
        return;
    }
    cout << "Enter amount to deposit: ";
    double amount;
    cin >> amount;
    cin.ignore();  
    if (amount <= 0) {
        cout << "Invalid deposit amount." << endl;
        return;
    }
    balances[index] += amount;
    cout << "Deposit successful. New balance: $" << balances[index] << endl;
}
void withdrawMoney(string accountNumbers[], double balances[], int numAccounts) {
    cout << "Enter account number for withdrawal: ";
    string accountNumber;
    getline(cin, accountNumber);
    int index = findAccountIndex(accountNumbers, numAccounts, accountNumber);
    if (index == -1) {
        cout << "Account not found." << endl;
        return;
    }
    cout << "Enter amount to withdraw: ";
    double amount;
    cin >> amount;
    cin.ignore();  
    if (amount <= 0) {
        cout << "Invalid withdrawal amount." << endl;
        return;
    }
    if (amount > balances[index]) {
        cout << "Insufficient funds." << endl;
        return;
    }

    balances[index] -= amount;
    cout << "Withdrawal successful. New balance: $" << balances[index] << endl;
}
void checkBalance(string accountNumbers[], double balances[], int numAccounts) {
    cout << "Enter account number to check balance: ";
    string accountNumber;
    getline(cin, accountNumber);
    int index = findAccountIndex(accountNumbers, numAccounts, accountNumber);
    if (index == -1) {
        cout << "Account not found." << endl;
        return;
    }
    cout << "Account balance: $" << balances[index] << endl;
}
int findAccountIndex(string accountNumbers[], int numAccounts, string accountNumber) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accountNumbers[i] == accountNumber) {
            return i;
        }
    }
    return -1;  
}