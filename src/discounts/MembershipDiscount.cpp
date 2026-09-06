#include "MembershipDiscount.h"

#include <stdexcept>

MembershipDiscount::MembershipDiscount(
    double premiumDiscountPercentage
)
{
    if (premiumDiscountPercentage < 0 ||
        premiumDiscountPercentage > 100)
    {
        throw std::invalid_argument(
            "Discount percentage must be between 0 and 100."
        );
    }

    this->premiumDiscountPercentage = premiumDiscountPercentage;
}

double MembershipDiscount::calculateDiscount(
    double price,
    int quantity,
    MembershipType membership
) const
{
    if (membership != MembershipType::Premium)
        return 0.0;

    return price * quantity * premiumDiscountPercentage / 100.0;
}
