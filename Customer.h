#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>

class Transaction {
public:
    std::string type;
    double amount;
    std::string date;

    Transaction(std::string t, double a, std::string d)
        : type(t), amount(a), date(d) {}
};

class Customer {
private:
    int id;
    std::string name;
    std::string password;
    double balance;
    std::vector<Transaction> transactions;

public:
    Customer(int id, std::string name, std::string password, double balance = 0.0)
        : id(id), name(name), password(password), balance(balance) {}

    bool login(const std::string& enteredPassword) {
        if (password == enteredPassword) {
            std::cout << "Login successful.\n";
            return true;
        } else {
            std::cout << "Incorrect password.\n";
            return false;
        }
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount, "2024-12-05")); // Date can be dynamic
        std::cout << "Deposited " << amount << ". New balance: " << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactions.push_back(Transaction("Withdrawal", amount, "2024-12-05"));
            std::cout << "Withdrew " << amount << ". New balance: " << balance << "\n";
        } else {
            std::cout << "Insufficient funds.\n";
        }
    }

    void showBalance() const {
        std::cout << "Current balance: " << balance << "\n";
    }

    void showTransactionHistory() const {
        std::cout << "Transaction History:\n";
        for (const auto& txn : transactions) {
            std::cout << txn.type << ": " << txn.amount << " on " << txn.date << "\n";
        }
    }

    int getID() const { return id; }
    std::string getName() const { return name; }
};

#endif
