#include "../include/MembershipDiscount.h"

MembershipDiscount::MembershipDiscount(
    double premiumDiscountPercentage
)
    : premiumDiscountPercentage(premiumDiscountPercentage)
{
}

double MembershipDiscount::calculateDiscount(
    double price,
    int quantity,
    MembershipType membership
) const
{
    if (membership != MembershipType::Premium)
    {
        return 0.0;
    }

    double subtotal = price * quantity;

    return subtotal *
           premiumDiscountPercentage / 100.0;
}
