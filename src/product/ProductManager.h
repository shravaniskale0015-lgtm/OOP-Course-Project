#ifndef PRODUCT_MANAGER_H
#define PRODUCT_MANAGER_H

#include "Product.h"
#include <vector>
#include <string>

using namespace std;

class ProductManager
{
private:
    vector<Product> products;

public:
    // Add product
    bool addProduct(const Product& product);

    // Search product
    Product* searchProduct(int productId);
    Product* searchProduct(const string& name);

    // Update product
    bool updateProduct(int productId, const Product& updatedProduct);

    // Delete product
    bool deleteProduct(int productId);

    // Display all products
    void displayProducts() const;

    // Check whether product exists
    bool productExists(int productId) const;

    // Number of products
    int getProductCount() const;
};

#endif