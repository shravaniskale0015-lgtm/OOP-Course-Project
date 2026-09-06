#include "CartItem.h"

#include <iostream>
#include <stdexcept>

using namespace std;

CartItem::CartItem(const Product& product, int quantity)
    : product(product), quantity(quantity)
{
    if (quantity <= 0)
        throw invalid_argument("Cart quantity must be positive.");

    if (quantity > product.getStockQuantity())
        throw invalid_argument("Requested quantity exceeds available stock.");
}

Product CartItem::getProduct() const
{
    return product;
}

int CartItem::getQuantity() const
{
    return quantity;
}

double CartItem::getSubtotal() const
{
    return product.getPrice() * quantity;
}

void CartItem::display() const
{
    cout << product.getName()
         << " x " << quantity
         << " = " << getSubtotal()
         << endl;
}
