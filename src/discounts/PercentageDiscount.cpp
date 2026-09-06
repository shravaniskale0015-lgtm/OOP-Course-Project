#include "PercentageDiscount.h"

#include <stdexcept>

PercentageDiscount::PercentageDiscount(double percentage)
{
    if (percentage < 0 || percentage > 100)
        throw std::invalid_argument("Percentage must be between 0 and 100.");

    this->percentage = percentage;
}

double PercentageDiscount::calculateDiscount(
    double price,
    int quantity,
    MembershipType membership
) const
{
    (void)membership;
    return price * quantity * percentage / 100.0;
}
