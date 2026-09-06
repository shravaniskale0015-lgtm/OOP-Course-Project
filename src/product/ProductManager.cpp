#include "ProductManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Add Product
bool ProductManager::addProduct(const Product& product)
{
    if (productExists(product.getProductId()))
    {
        return false;
    }

    products.push_back(product);
    return true;
}

// Search by ID
Product* ProductManager::searchProduct(int productId)
{
    for (auto& product : products)
    {
        if (product.getProductId() == productId)
        {
            return &product;
        }
    }

    return nullptr;
}

// Search by name
Product* ProductManager::searchProduct(const string& name)
{
    for (auto& product : products)
    {
        if (product.getName() == name)
        {
            return &product;
        }
    }

    return nullptr;
}

// Update Product
bool ProductManager::updateProduct(int productId,
                                    const Product& updatedProduct)
{
    for (auto& product : products)
    {
        if (product.getProductId() == productId)
        {
            product.setName(updatedProduct.getName());
            product.setCategory(updatedProduct.getCategory());
            product.setPrice(updatedProduct.getPrice());
            product.setStockQuantity(updatedProduct.getStockQuantity());

            return true;
        }
    }

    return false;
}

// Delete Product
bool ProductManager::deleteProduct(int productId)
{
    for (auto it = products.begin(); it != products.end(); ++it)
    {
        if (it->getProductId() == productId)
        {
            products.erase(it);
            return true;
        }
    }

    return false;
}

// Display Products
void ProductManager::displayProducts() const
{
    if (products.empty())
    {
        cout << "No products available.\n";
        return;
    }

    cout << "\nProduct List:\n";

    cout << left
         << setw(8) << "ID"
         << setw(25) << "Name"
         << setw(20) << "Category"
         << setw(12) << "Price"
         << setw(8) << "Stock"
         << endl;

    cout << string(73, '-') << endl;

    for (const auto& product : products)
    {
        product.display();
    }
}

// Check Product Exists
bool ProductManager::productExists(int productId) const
{
    for (const auto& product : products)
    {
        if (product.getProductId() == productId)
        {
            return true;
        }
    }

    return false;
}

// Get Product Count
int ProductManager::getProductCount() const
{
    return static_cast<int>(products.size());
}