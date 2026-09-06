#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
private:
    int productId;
    std::string name;
    std::string category;
    double price;
    int stockQuantity;

public:
    // Constructors
    Product();
    Product(int id, std::string name, std::string category,
            double price, int stockQuantity);

    // Getters
    int getProductId() const;
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    int getStockQuantity() const;

    // Setters
    void setName(std::string name);
    void setCategory(std::string category);
    void setPrice(double price);
    void setStockQuantity(int stockQuantity);

    // Other member functions
    void updateStock(int quantity);
    void display() const;
};

#endif