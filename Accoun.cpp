#include "Account.h"

Node::Node(Transaction t) : data(t), next(nullptr) {}

Account::Account(string accNum, string name, double initialBalance)
    : accountNumber(accNum), customerName(name), balance(initialBalance), transactionHistory(nullptr) {}

void Account::deposit(double amount, string date) {
    balance += amount;
    Transaction t("Deposit", amount, date);
    addTransaction(t);
    cout << "Deposited " << amount << ". New balance: " << balance << endl;
}

void Account::withdraw(double amount, string date) {
    if (amount <= balance) {
        balance -= amount;
        Transaction t("Withdraw", amount, date);
        addTransaction(t);
        cout << "Withdrew " << amount << ". New balance: " << balance << endl;
    } else {
        cout << "Insufficient funds!" << endl;
    }
}

void Account::viewBalance() {
    cout << "Balance for account " << accountNumber << ": " << balance << endl;
}

void Account::addTransaction(Transaction t) {
    Node* newTransaction = new Node(t);
    if (!transactionHistory) {
        transactionHistory = newTransaction;
    } else {
        Node* temp = transactionHistory;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newTransaction;
    }
}

void Account::viewTransactionHistory() {
    Node* temp = transactionHistory;
    if (!temp) {
        cout << "No transactions found." << endl;
        return;
    }
    cout << "Transaction History for account " << accountNumber << ":\n";
    while (temp) {
        cout << temp->data.type << ": " << temp->data.amount << " on " << temp->data.date << endl;
        temp = temp->next;
    }
}

Account::~Account() {
    while (transactionHistory) {
        Node* temp = transactionHistory;
        transactionHistory = transactionHistory->next;
        delete temp;
    }
}
