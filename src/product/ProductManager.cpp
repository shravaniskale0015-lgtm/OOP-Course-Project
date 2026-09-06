#include "ProductManager.h"
#include <iostream>

using namespace std;

// Add a product
void ProductManager::addProduct(const Product& product)
{
    products.push_back(product);
}

// Display all products
void ProductManager::displayProducts() const
{
    if (products.empty())
    {
        cout << "No products available.\n";
        return;
    }

    cout << "\nProduct List:\n";
    cout << "ID\tName\t\tCategory\tPrice\t\tStock\n";
    cout << "------------------------------------------------------------\n";

    for (const Product& product : products)
    {
        product.display();
    }
}

// Search product by ID
Product* ProductManager::searchProduct(int productId)
{
    for (Product& product : products)
    {
        if (product.getProductId() == productId)
        {
            return &product;
        }
    }

    return nullptr;
}

// Update product
bool ProductManager::updateProduct(int productId,
                                    const Product& updatedProduct)
{
    Product* product = searchProduct(productId);

    if (product == nullptr)
    {
        return false;
    }

    product->setName(updatedProduct.getName());
    product->setCategory(updatedProduct.getCategory());
    product->setPrice(updatedProduct.getPrice());
    product->setStockQuantity(updatedProduct.getStockQuantity());

    return true;
}

// Delete product
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