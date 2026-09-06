#ifndef PRODUCT_MANAGER_H
#define PRODUCT_MANAGER_H

#include <vector>
#include "Product.h"

class ProductManager
{
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product);
    void displayProducts() const;
    Product* searchProduct(int productId);
    bool updateProduct(int productId, const Product& updatedProduct);
    bool deleteProduct(int productId);
};

#endif