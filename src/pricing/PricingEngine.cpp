#include "PricingEngine.h"

double PricingEngine::calculateSubtotal(const Cart& cart) const
{
    return cart.getTotal();
}

double PricingEngine::calculateTotalDiscount(
    const Cart& cart,
    const vector<DiscountRule*>& rules,
    MembershipType membership
) const
{
    double totalDiscount = 0.0;

    for (const CartItem& item : cart.getItems())
    {
        double itemDiscount = 0.0;

        for (DiscountRule* rule : rules)
        {
            if (rule != nullptr)
            {
                itemDiscount += rule->calculateDiscount(
                    item.getProduct().getPrice(),
                    item.getQuantity(),
                    membership
                );
            }
        }

        if (itemDiscount > item.getSubtotal())
            itemDiscount = item.getSubtotal();

        totalDiscount += itemDiscount;
    }

    return totalDiscount;
}

double PricingEngine::calculateFinalPrice(
    const Cart& cart,
    const vector<DiscountRule*>& rules,
    MembershipType membership
) const
{
    double subtotal = calculateSubtotal(cart);
    double discount = calculateTotalDiscount(cart, rules, membership);

    double finalPrice = subtotal - discount;

    if (finalPrice < 0.0)
        finalPrice = 0.0;

    return finalPrice;
}
