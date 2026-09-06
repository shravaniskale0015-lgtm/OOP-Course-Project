#include "Product.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Default constructor
Product::Product()
{
    productId = 0;
    name = "";
    category = "";
    price = 0.0;
    stockQuantity = 0;
}

// Parameterized constructor
Product::Product(int id, string name, string category,
                 double price, int stockQuantity)
{
    if (id <= 0)
        throw invalid_argument("Product ID must be positive.");

    if (name.empty())
        throw invalid_argument("Product name cannot be empty.");

    if (category.empty())
        throw invalid_argument("Product category cannot be empty.");

    if (price < 0)
        throw invalid_argument("Product price cannot be negative.");

    if (stockQuantity < 0)
        throw invalid_argument("Stock quantity cannot be negative.");

    productId = id;
    this->name = name;
    this->category = category;
    this->price = price;
    this->stockQuantity = stockQuantity;
}

// Getters
int Product::getProductId() const
{
    return productId;
}

string Product::getName() const
{
    return name;
}

string Product::getCategory() const
{
    return category;
}

double Product::getPrice() const
{
    return price;
}

int Product::getStockQuantity() const
{
    return stockQuantity;
}

// Setters
void Product::setName(string name)
{
    if (name.empty())
        throw invalid_argument("Product name cannot be empty.");

    this->name = name;
}

void Product::setCategory(string category)
{
    if (category.empty())
        throw invalid_argument("Product category cannot be empty.");

    this->category = category;
}

void Product::setPrice(double price)
{
    if (price < 0)
        throw invalid_argument("Product price cannot be negative.");

    this->price = price;
}

void Product::setStockQuantity(int stockQuantity)
{
    if (stockQuantity < 0)
        throw invalid_argument("Stock quantity cannot be negative.");

    this->stockQuantity = stockQuantity;
}

// Update stock
void Product::updateStock(int quantity)
{
    if (stockQuantity + quantity < 0)
        throw invalid_argument("Stock quantity cannot become negative.");

    stockQuantity += quantity;
}

// Display product
void Product::display() const
{
    cout << left
         << setw(8) << productId
         << setw(20) << name
         << setw(15) << category
         << setw(12) << fixed << setprecision(2) << price
         << setw(10) << stockQuantity
         << endl;
}