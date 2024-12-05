#include "Admin.h"
#include <iostream>
#include <algorithm>

// Constructor
Admin::Admin(const std::string& user, const std::string& pass) 
    : username(user), password(pass) {}

// Login Function
bool Admin::login(const std::string& user, const std::string& pass) {
    if (username == user && password == pass) {
        std::cout << "Admin login successful.\n";
        return true;
    } else {
        std::cout << "Invalid username or password.\n";
        return false;
    }
}

// Add a new customer
void Admin::addCustomer(std::vector<Customer>& customers, const Customer& newCustomer) {
    customers.push_back(newCustomer);
    std::cout << "Customer added successfully.\n";
}

// Remove a customer by ID
void Admin::removeCustomer(std::vector<Customer>& customers, int customerID) {
    auto it = std::remove_if(customers.begin(), customers.end(),
                             [customerID](const Customer& customer) { return customer.getID() == customerID; });

    if (it != customers.end()) {
        customers.erase(it, customers.end());
        std::cout << "Customer removed successfully.\n";
    } else {
        std::cout << "Customer ID not found.\n";
    }
}

// Display all customers
void Admin::displayCustomers(const std::vector<Customer>& customers) const {
    std::cout << "Customer List:\n";
    for (const auto& customer : customers) {
        std::cout << "ID: " << customer.getID() << ", Name: " << customer.getName() << "\n";
    }
}
