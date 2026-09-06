#ifndef MEMBERSHIP_DISCOUNT_H
#define MEMBERSHIP_DISCOUNT_H

#include "DiscountRule.h"

class MembershipDiscount : public DiscountRule
{
private:
    double premiumDiscountPercentage;

public:
    MembershipDiscount(double premiumDiscountPercentage);

    double calculateDiscount(
        double price,
        int quantity,
        MembershipType membership
    ) const override;
};

#endif
