#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(int id, string n, string e, string membership)
{
    customerId = id;
    name = n;
    email = e;
    membershipType = membership;
}

void Customer::display()
{
    cout << "Customer ID: " << customerId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Membership: " << membershipType << endl;
}

string Customer::getMembershipType()
{
    return membershipType;
}