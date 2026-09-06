#include "Product.h"
#include <stdexcept>
#include <iomanip>

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
Product::Product(int productId,
                 const string& name,
                 const string& category,
                 double price,
                 int stockQuantity)
{
    if (productId <= 0)
    {
        throw invalid_argument("Product ID must be positive.");
    }

    if (name.empty())
    {
        throw invalid_argument("Product name cannot be empty.");
    }

    if (category.empty())
    {
        throw invalid_argument("Product category cannot be empty.");
    }

    if (price < 0)
    {
        throw invalid_argument("Product price cannot be negative.");
    }

    if (stockQuantity < 0)
    {
        throw invalid_argument("Stock quantity cannot be negative.");
    }

    this->productId = productId;
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

void Product::setName(const string& name)
{
    if (name.empty())
    {
        throw invalid_argument("Product name cannot be empty.");
    }

    this->name = name;
}

void Product::setCategory(const string& category)
{
    if (category.empty())
    {
        throw invalid_argument("Product category cannot be empty.");
    }

    this->category = category;
}

void Product::setPrice(double price)
{
    if (price < 0)
    {
        throw invalid_argument("Product price cannot be negative.");
    }

    this->price = price;
}

void Product::setStockQuantity(int stockQuantity)
{
    if (stockQuantity < 0)
    {
        throw invalid_argument("Stock quantity cannot be negative.");
    }

    this->stockQuantity = stockQuantity;
}

// Display

void Product::display() const
{
    cout << left
         << setw(8) << productId
         << setw(25) << name
         << setw(20) << category
         << setw(12) << fixed << setprecision(2) << price
         << setw(8) << stockQuantity
         << endl;
}