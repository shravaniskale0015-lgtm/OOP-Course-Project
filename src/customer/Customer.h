#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer
{
private:
    int customerId;
    string name;
    string email;
    string membershipType;

public:
    Customer(
        int id,
        const string& name,
        const string& email,
        const string& membership
    );

    void display() const;

    int getCustomerId() const;
    string getName() const;
    string getEmail() const;
    string getMembershipType() const;

    void setName(const string& name);
    void setEmail(const string& email);
    void setMembershipType(const string& membership);
};

#endif