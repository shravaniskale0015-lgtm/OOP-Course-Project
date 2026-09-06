#include <iostream>
#include <iomanip>

#include "../include/DiscountRule.h"
#include "../include/PercentageDiscount.h"
#include "../include/QuantityDiscount.h"
#include "../include/MembershipDiscount.h"

using namespace std;

int main()
{
    double price = 10000.00;
    int quantity = 3;

    MembershipType membership =
        MembershipType::Premium;

    cout << fixed << setprecision(2);

    cout << "============================================"
         << endl;

    cout << "       DISCOUNT RULE ENGINE - MEMBER 3"
         << endl;

    cout << "============================================"
         << endl;

    cout << "Product Price : Rs. "
         << price << endl;

    cout << "Quantity      : "
         << quantity << endl;

    cout << "Membership    : Premium"
         << endl;


    // Percentage Discount
    PercentageDiscount percentageRule(10);

    DiscountRule* rule1 = &percentageRule;

    double percentageDiscount =
        rule1->calculateDiscount(
            price,
            quantity,
            membership
        );

    cout << "\nPercentage Discount (10%)"
         << endl;

    cout << "Discount Amount : Rs. "
         << percentageDiscount << endl;


    // Quantity Discount
    QuantityDiscount quantityRule(3, 5);

    DiscountRule* rule2 = &quantityRule;

    double quantityDiscount =
        rule2->calculateDiscount(
            price,
            quantity,
            membership
        );

    cout << "\nQuantity Discount (3+ items = 5%)"
         << endl;

    cout << "Discount Amount : Rs. "
         << quantityDiscount << endl;


    // Membership Discount
    MembershipDiscount membershipRule(5);

    DiscountRule* rule3 = &membershipRule;

    double membershipDiscount =
        rule3->calculateDiscount(
            price,
            quantity,
            membership
        );

    cout << "\nPremium Membership Discount (5%)"
         << endl;

    cout << "Discount Amount : Rs. "
         << membershipDiscount << endl;


    // Final calculation
    double subtotal =
        price * quantity;

    double totalDiscount =
        percentageDiscount +
        quantityDiscount +
        membershipDiscount;

    double finalAmount =
        subtotal - totalDiscount;


    cout << "\n--------------------------------------------"
         << endl;

    cout << "Subtotal       : Rs. "
         << subtotal << endl;

    cout << "Total Discount : Rs. "
         << totalDiscount << endl;

    cout << "Final Amount   : Rs. "
         << finalAmount << endl;

    cout << "============================================"
         << endl;

    return 0;
}
