#ifndef CART_H
#define CART_H

#include "CartItem.h"

#include <vector>

using namespace std;

class Cart
{
private:
    vector<CartItem> items;

public:
    void addToCart(const Product& product, int quantity);
    bool removeFromCart(int productId);

    void displayCart() const;

    double getTotal() const;

    const vector<CartItem>& getItems() const;

    void clearCart();
};

#endif
