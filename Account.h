#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include <string>
#include <iostream>
#include <queue>  // For Queue (optional)
#include <stack>  // For Stack (optional)

using namespace std;

struct Node {
    Transaction data;
    Node* next;

    Node(Transaction t);
};

class Account {
private:
    string accountNumber;
    string customerName;
    double balance;
    Node* transactionHistory;  // Linked List of transactions (or we can use Queue/Stack)

public:
    Account(string accNum, string name, double initialBalance);
    void deposit(double amount, string date);
    void withdraw(double amount, string date);
    void viewBalance();
    void addTransaction(Transaction t);
    void viewTransactionHistory();
    ~Account();
};

#endif
