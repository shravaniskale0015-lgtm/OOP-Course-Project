#include "Customer.h"

#include <iostream>
#include <stdexcept>

using namespace std;

Customer::Customer(
    int id,
    const string& name,
    const string& email,
    const string& membership
)
{
    if (id <= 0)
        throw invalid_argument("Customer ID must be positive.");

    if (name.empty())
        throw invalid_argument("Customer name cannot be empty.");

    if (email.empty())
        throw invalid_argument("Customer email cannot be empty.");

    if (membership != "Regular" && membership != "Premium")
        throw invalid_argument("Membership must be Regular or Premium.");

    customerId = id;
    this->name = name;
    this->email = email;
    membershipType = membership;
}

void Customer::display() const
{
    cout << "Customer ID: " << customerId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Membership: " << membershipType << endl;
}

int Customer::getCustomerId() const
{
    return customerId;
}

string Customer::getName() const
{
    return name;
}

string Customer::getEmail() const
{
    return email;
}

string Customer::getMembershipType() const
{
    return membershipType;
}

void Customer::setName(const string& name)
{
    if (name.empty())
        throw invalid_argument("Customer name cannot be empty.");

    this->name = name;
}

void Customer::setEmail(const string& email)
{
    if (email.empty())
        throw invalid_argument("Customer email cannot be empty.");

    this->email = email;
}

void Customer::setMembershipType(const string& membership)
{
    if (membership != "Regular" && membership != "Premium")
        throw invalid_argument("Membership must be Regular or Premium.");

    membershipType = membership;
}
