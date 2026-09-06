#include "Cart.h"

#include <iostream>

using namespace std;

void Cart::addToCart(const Product& product, int quantity)
{
    for (CartItem& item : items)
    {
        if (item.getProduct().getProductId() == product.getProductId())
        {
            int newQuantity = item.getQuantity() + quantity;

            if (newQuantity > product.getStockQuantity())
                throw invalid_argument(
                    "Total cart quantity exceeds available stock."
                );

            item = CartItem(product, newQuantity);
            return;
        }
    }

    items.push_back(CartItem(product, quantity));
}

bool Cart::removeFromCart(int productId)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->getProduct().getProductId() == productId)
        {
            items.erase(it);
            return true;
        }
    }

    return false;
}

void Cart::displayCart() const
{
    cout << "\n--- CART ---\n";

    if (items.empty())
    {
        cout << "Cart is empty.\n";
        return;
    }

    for (const CartItem& item : items)
        item.display();

    cout << "Cart Total: " << getTotal() << endl;
}

double Cart::getTotal() const
{
    double total = 0.0;

    for (const CartItem& item : items)
        total += item.getSubtotal();

    return total;
}

const vector<CartItem>& Cart::getItems() const
{
    return items;
}

void Cart::clearCart()
{
    items.clear();
}
