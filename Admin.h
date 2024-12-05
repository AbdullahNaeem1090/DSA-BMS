#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>
#include "Customer.h" // Include if needed for customer-related functions

class Admin {
private:
    std::string username;
    std::string password;

public:
    Admin(const std::string& user, const std::string& pass);
    bool login(const std::string& user, const std::string& pass);
    void addCustomer(std::vector<Customer>& customers, const Customer& newCustomer);
    void removeCustomer(std::vector<Customer>& customers, int customerID);
    void displayCustomers(const std::vector<Customer>& customers) const;
};

#endif
