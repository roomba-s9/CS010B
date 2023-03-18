#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <vector>
#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string, string);
    string customerName() const;
    string date() const;
    int numItemsInCart() const;
    double costOfCart() const;
    void printTotal() const;
    void printDescriptions() const;
    void addItem(ItemToPurchase);
    void removeItem(string);
    void modifyItem(ItemToPurchase);

private:
    string _customerName;
    string _currentDate;
    vector <ItemToPurchase> _cartItems;
    // ItemToPurchase.h names
    // string _name;
    // int _price;
    // int _quantity;
    // string _description;
};

#endif