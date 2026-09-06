#include "../include/PercentageDiscount.h"

PercentageDiscount::PercentageDiscount(double percentage)
    : percentage(percentage)
{
}

double PercentageDiscount::calculateDiscount(
    double price,
    int quantity,
    MembershipType membership
) const
{
    double subtotal = price * quantity;

    return subtotal * percentage / 100.0;
}
