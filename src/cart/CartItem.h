#ifndef CART_ITEM_H
#define CART_ITEM_H

#include "../product/Product.h"

class CartItem
{
private:
    Product product;
    int quantity;

public:
    CartItem(const Product& product, int quantity);

    Product getProduct() const;
    int getQuantity() const;

    double getSubtotal() const;

    void display() const;
};

#endif
