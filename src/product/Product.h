#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    int productId;
    string name;
    string category;
    double price;
    int stockQuantity;

public:
    // Default constructor
    Product();

    // Parameterized constructor
    Product(int productId,
            const string& name,
            const string& category,
            double price,
            int stockQuantity);

    // Getters
    int getProductId() const;
    string getName() const;
    string getCategory() const;
    double getPrice() const;
    int getStockQuantity() const;

    // Setters
    void setName(const string& name);
    void setCategory(const string& category);
    void setPrice(double price);
    void setStockQuantity(int stockQuantity);

    // Display product information
    void display() const;
};

#endif