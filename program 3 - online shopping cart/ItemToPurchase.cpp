#include <iostream>
#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase() {
    this->_name = "none";
    this->_description = "none";
    this->_price = 0;
    this->_quantity = 0;
}

ItemToPurchase::ItemToPurchase(string n, string d, int p, int q) {
    this->_name = n;
    this->_description = d;
    this->_price = p;
    this->_quantity = q;
}

void ItemToPurchase::setName(string n) {
    this->_name = n;
}

void ItemToPurchase::setPrice(int n) {
    this->_price = n;
}

void ItemToPurchase::setQuantity(int n) {
    this->_quantity = n;
}

void ItemToPurchase::setDescription(string n) {
    this->_description = n;
}

string ItemToPurchase::name() const {
    return _name;
}

int ItemToPurchase::price() const {
    return _price;
}

int ItemToPurchase::quantity() const {
    return _quantity;
}

string ItemToPurchase::description() const {
    return _description;
}

void ItemToPurchase::printItemCost() const {
    cout << _name << ' ' << _quantity << " @ $" << _price << " = $" << _quantity * _price;
}

void ItemToPurchase::printItemDescription() const {
    cout << _name << ": " << _description;
}