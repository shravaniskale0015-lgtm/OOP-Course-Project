#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "../product/Product.h"

#include <string>

using namespace std;

class FileManager
{
public:
    static void saveProduct(
        const Product& product,
        const string& filename
    );

    static void saveTransaction(
        double subtotal,
        double discount,
        double finalAmount,
        const string& filename
    );
};

#endif
