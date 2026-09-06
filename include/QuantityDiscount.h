#ifndef QUANTITY_DISCOUNT_H
#define QUANTITY_DISCOUNT_H

#include "DiscountRule.h"

class QuantityDiscount : public DiscountRule
{
private:
    int minimumQuantity;
    double discountPercentage;

public:

    QuantityDiscount(
        int minimumQuantity,
        double discountPercentage
    );

    double calculateDiscount(
        double price,
        int quantity,
        MembershipType membership
    ) const override;
};

#endif
