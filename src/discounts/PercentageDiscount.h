#ifndef PERCENTAGE_DISCOUNT_H
#define PERCENTAGE_DISCOUNT_H

#include "DiscountRule.h"

class PercentageDiscount : public DiscountRule
{
private:
    double percentage;

public:
    PercentageDiscount(double percentage);

    double calculateDiscount(
        double price,
        int quantity,
        MembershipType membership
    ) const override;
};

#endif
