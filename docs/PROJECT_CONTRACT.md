# OOP Course Project — Project Contract

## Project
Dynamic Pricing & Discount Rule Engine

## Language
C++

## Current Mid-Sem Scope
- Product Management
- Customer Management
- Cart Management
- Basic Discount Rules
- Basic Pricing Calculation
- Basic File Handling
- Basic Exception Handling
- Console Interface

## Main Modules

Product
    ↓
Customer
    ↓
Cart
    ↓
Discount Rules
    ↓
Pricing Engine
    ↓
Bill / Transaction
    ↓
File Storage

## Folder Structure

src/
├── product/
├── customer/
├── cart/
├── discounts/
├── pricing/
└── storage/

data/
docs/

main.cpp

## Main Classes

Product
ProductManager

Customer
CustomerManager

CartItem
Cart

DiscountRule
PercentageDiscount
QuantityDiscount
MembershipDiscount

PricingEngine

FileManager

## Important Rules

1. Only one Product class exists.
2. Only one Customer class exists.
3. Only one Cart class exists.
4. DiscountRule is the base class for discount rules.
5. Do not create duplicate classes.
6. Do not modify another member's module without discussing it first.
7. Header files define the agreed interface between modules.
8. Keep the project console-based and simple.
9. Use OOP concepts naturally, not unnecessarily.
10. main.cpp will eventually integrate all modules.

## Dependency Direction

Product
    ↓
Cart
    ↓
DiscountRule
    ↓
PricingEngine
    ↓
FileManager

PricingEngine should work with the DiscountRule base class,
not directly depend on individual discount classes.

## Mid-Sem Goal

A user should be able to:

1. View/add products
2. Manage customers
3. Add products to a cart
4. Apply basic discount rules
5. Calculate final price
6. Display a basic bill
7. Save basic transaction/data information