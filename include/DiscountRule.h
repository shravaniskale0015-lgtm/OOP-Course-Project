#ifndef DISCOUNT_RULE_H
#define DISCOUNT_RULE_H

enum class MembershipType
{
    Regular,
    Premium
};

class DiscountRule
{
public:

    virtual double calculateDiscount(
        double price,
        int quantity,
        MembershipType membership
    ) const = 0;

    virtual ~DiscountRule();
};

#endif
