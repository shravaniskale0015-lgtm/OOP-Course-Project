#ifndef PRICING_ENGINE_H
#define PRICING_ENGINE_H

#include "../cart/Cart.h"
#include "../discounts/DiscountRule.h"

#include <vector>

using namespace std;

class PricingEngine
{
public:
    double calculateSubtotal(const Cart& cart) const;

    double calculateTotalDiscount(
        const Cart& cart,
        const vector<DiscountRule*>& rules,
        MembershipType membership
    ) const;

    double calculateFinalPrice(
        const Cart& cart,
        const vector<DiscountRule*>& rules,
        MembershipType membership
    ) const;
};

#endif
