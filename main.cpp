#include <iostream>
#include <vector>
#include <stdexcept>

#include "src/product/Product.h"
#include "src/product/ProductManager.h"
#include "src/customer/Customer.h"
#include "src/cart/Cart.h"
#include "src/discounts/PercentageDiscount.h"
#include "src/discounts/QuantityDiscount.h"
#include "src/discounts/MembershipDiscount.h"
#include "src/pricing/PricingEngine.h"
#include "src/storage/FileManager.h"

using namespace std;

int main()
{
    try
    {
        cout << "====================================\n";
        cout << " DYNAMIC PRICING & DISCOUNT ENGINE\n";
        cout << "====================================\n";

        // Product Management
        ProductManager productManager;

        Product laptop(
            101,
            "Gaming Laptop",
            "Electronics",
            85000,
            8
        );

        Product mouse(
            103,
            "Mouse",
            "Electronics",
            800,
            30
        );

        productManager.addProduct(laptop);
        productManager.addProduct(mouse);

        cout << "\n--- PRODUCTS ---\n";
        productManager.displayProducts();

        // Customer Management
        Customer customer(
            201,
            "Shravani",
            "shravani@example.com",
            "Premium"
        );

        cout << "\n--- CUSTOMER ---\n";
        customer.display();

        // Cart Management
        Cart cart;

        cart.addToCart(laptop, 1);
        cart.addToCart(mouse, 3);

        cart.displayCart();

        // Discount Rules
        PercentageDiscount percentageDiscount(5.0);
        QuantityDiscount quantityDiscount(3, 10.0);
        MembershipDiscount membershipDiscount(5.0);

        vector<DiscountRule*> rules;

        rules.push_back(&percentageDiscount);
        rules.push_back(&quantityDiscount);
        rules.push_back(&membershipDiscount);

        MembershipType membership;

        if (customer.getMembershipType() == "Premium")
            membership = MembershipType::Premium;
        else
            membership = MembershipType::Regular;

        // Pricing Engine
        PricingEngine pricingEngine;

        double subtotal =
            pricingEngine.calculateSubtotal(cart);

        double discount =
            pricingEngine.calculateTotalDiscount(
                cart,
                rules,
                membership
            );

        double finalAmount =
            pricingEngine.calculateFinalPrice(
                cart,
                rules,
                membership
            );

        // Final Bill
        cout << "\n====================================\n";
        cout << "              FINAL BILL\n";
        cout << "====================================\n";

        cout << "Customer: "
             << customer.getName() << endl;

        cout << "Membership: "
             << customer.getMembershipType() << endl;

        cout << "Subtotal: Rs. "
             << subtotal << endl;

        cout << "Total Discount: Rs. "
             << discount << endl;

        cout << "Final Amount: Rs. "
             << finalAmount << endl;

        cout << "====================================\n";

        // File Handling
        FileManager::saveProduct(
            laptop,
            "data/products.txt"
        );

        FileManager::saveProduct(
            mouse,
            "data/products.txt"
        );

        FileManager::saveTransaction(
            subtotal,
            discount,
            finalAmount,
            "data/transactions.txt"
        );

        cout << "\nData saved successfully.\n";
        cout << "====================================\n";

        return 0;
    }
    catch (const exception& e)
    {
        cerr << "\nError: " << e.what() << endl;
        return 1;
    }
}
