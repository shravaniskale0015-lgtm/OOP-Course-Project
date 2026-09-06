#include <iostream>
#include "src/product/ProductManager.h"

using namespace std;

int main()
{
    ProductManager manager;

    // Add products
    manager.addProduct(Product(101, "Laptop", "Electronics", 80000, 10));
    manager.addProduct(Product(102, "T-Shirt", "Clothing", 1200, 25));
    manager.addProduct(Product(103, "Mouse", "Electronics", 800, 30));

    // Display all products
    cout << "\n--- ALL PRODUCTS ---\n";
    manager.displayProducts();

    // Search product
    cout << "\n--- SEARCH PRODUCT ---\n";

    Product* product = manager.searchProduct(101);

    if (product != nullptr)
    {
        cout << "Product found: " << product->getName() << endl;
    }
    else
    {
        cout << "Product not found.\n";
    }

    // Update product
    cout << "\n--- UPDATE PRODUCT ---\n";

    Product updatedProduct(
        101,
        "Gaming Laptop",
        "Electronics",
        85000,
        8
    );

    if (manager.updateProduct(101, updatedProduct))
    {
        cout << "Product updated successfully.\n";
    }
    else
    {
        cout << "Product update failed.\n";
    }

    manager.displayProducts();

    // Delete product
    cout << "\n--- DELETE PRODUCT ---\n";

    if (manager.deleteProduct(102))
    {
        cout << "Product deleted successfully.\n";
    }
    else
    {
        cout << "Product deletion failed.\n";
    }

    manager.displayProducts();

    return 0;
}