#include "QuantityDiscount.h"

#include <stdexcept>

QuantityDiscount::QuantityDiscount(
    int minimumQuantity,
    double discountPercentage
)
{
    if (minimumQuantity <= 0)
        throw std::invalid_argument("Minimum quantity must be positive.");

    if (discountPercentage < 0 || discountPercentage > 100)
        throw std::invalid_argument(
            "Discount percentage must be between 0 and 100."
        );

    this->minimumQuantity = minimumQuantity;
    this->discountPercentage = discountPercentage;
}

double QuantityDiscount::calculateDiscount(
    double price,
    int quantity,
    MembershipType membership
) const
{
    (void)membership;

    if (quantity < minimumQuantity)
        return 0.0;

    return price * quantity * discountPercentage / 100.0;
}
