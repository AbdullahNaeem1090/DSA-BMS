#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
public:
    string type;  // "Deposit" or "Withdraw"
    double amount;
    string date;  // Transaction date

    Transaction(string t, double a, string d);
};

#endif
