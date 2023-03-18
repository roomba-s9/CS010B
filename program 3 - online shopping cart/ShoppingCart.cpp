#include <iostream>
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart() {
    this->_customerName = "none";
    this->_currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string n, string d) {
    this->_customerName = n;
    this->_currentDate = d;
}

string ShoppingCart::customerName() const {
    return _customerName;
}

string ShoppingCart::date() const {
    return _currentDate;
}

int ShoppingCart::numItemsInCart() const {
    int total = 0;
    for (auto x : _cartItems) {
        total += x.quantity();
    }
    return total;
}

double ShoppingCart::costOfCart() const {
    int total = 0;
    for (auto x : _cartItems) {
        total += x.price() * x.quantity();
    }
    return total;
}

void ShoppingCart::printTotal() const {
    cout << customerName() << "'s Shopping Cart - " << date() << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    for (auto x : _cartItems) {
        x.printItemCost();
        cout << endl;
    }

    if (numItemsInCart() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    cout << endl;
    cout << "Total: $" << costOfCart() << endl;
    cout << endl;
}

void ShoppingCart::printDescriptions() const {
    cout << customerName() << "'s Shopping Cart - " << date() << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for (auto x : _cartItems) {
        x.printItemDescription();
        cout << endl;
    }
    cout << endl;
}

void ShoppingCart::addItem(ItemToPurchase item) {
    _cartItems.push_back(item);
}

void ShoppingCart::removeItem(string n) {
    int index = -1;
    for (unsigned i = 0; i < _cartItems.size(); ++i) {
        if (_cartItems.at(i).name() == n) {
            index = i;
        }
    }

    if (index == -1) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }

    while (index != -1) {
        for (unsigned j = index; j < _cartItems.size() - 1; ++j) {
            _cartItems.at(j) = _cartItems.at(j + 1);
        }  
        _cartItems.pop_back();
        index = -1;
    }


}

void ShoppingCart::modifyItem(ItemToPurchase item) {
    string name = item.name();
    int index = -1;
    for (unsigned i = 0; i < _cartItems.size(); ++i) {
        if (name == _cartItems.at(i).name()){
            index = i;
        }
    }

    if (index != -1) {
        _cartItems.at(index).setQuantity(item.quantity());
    } else {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}