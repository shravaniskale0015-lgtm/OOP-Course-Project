#include "FileManager.h"

#include <fstream>
#include <stdexcept>

using namespace std;

void FileManager::saveProduct(
    const Product& product,
    const string& filename
)
{
    ofstream file(filename, ios::app);

    if (!file)
        throw runtime_error("Unable to open product file.");

    file << product.getProductId() << ","
         << product.getName() << ","
         << product.getCategory() << ","
         << product.getPrice() << ","
         << product.getStockQuantity()
         << "\n";

    file.close();
}

void FileManager::saveTransaction(
    double subtotal,
    double discount,
    double finalAmount,
    const string& filename
)
{
    ofstream file(filename, ios::app);

    if (!file)
        throw runtime_error("Unable to open transaction file.");

    file << "Subtotal: " << subtotal
         << ", Discount: " << discount
         << ", Final Amount: " << finalAmount
         << "\n";

    file.close();
}
