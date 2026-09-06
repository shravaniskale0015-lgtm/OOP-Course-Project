#include "../include/QuantityDiscount.h"

QuantityDiscount::QuantityDiscount(
    int minimumQuantity,
    double discountPercentage
)
    : minimumQuantity(minimumQuantity),
      discountPercentage(discountPercentage)
{
}

double QuantityDiscount::calculateDiscount(
    double price,
    int quantity,
    MembershipType membership
) const
{
    if (quantity < minimumQuantity)
    {
        return 0.0;
    }

    double subtotal = price * quantity;

    return subtotal * discountPercentage / 100.0;
}
