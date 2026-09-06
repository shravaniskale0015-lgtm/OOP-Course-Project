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
    Customer(int id, string n, string e, string membership);

    void display();
    string getMembershipType();
};

#endif