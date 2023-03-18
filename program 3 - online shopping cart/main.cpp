#include <iostream>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void printMenu(ShoppingCart cart) {
    char option;
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;

    cout << "Choose an option: " << endl;
    cin >> option;
    while (option != 'q') {
        if (option == 'o') {
            cout << endl << "OUTPUT SHOPPING CART" << endl;
            cart.printTotal();
            printMenu(cart);
        }
        if (option == 'i') {
            cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cart.printDescriptions();
            printMenu(cart);
        }
        if (option == 'a') {
            string name;
            string desc;
            int price;
            int qty;

            cout << endl << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: " << endl;
            getline(cin, name);
            getline(cin, name);
            cout << "Enter the item description: " << endl;
            getline(cin, desc);
            cout << "Enter the item price: " << endl;
            cin >> price;
            cout << "Enter the item quantity: " << endl;
            cin >> qty;
            cout << endl;
            ItemToPurchase item(name, desc, price, qty);
            cart.addItem(item);
            printMenu(cart);
        }
        if (option == 'd') {
            string name;
            cout << endl << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: ";
            getline(cin, name);
            getline(cin, name);
            cout << endl;
            cart.removeItem(name);
            cout << endl;
            printMenu(cart);
        }
        if (option == 'c') {
            string name;
            int qty;
            cout << endl << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: " << endl;
            getline(cin, name);
            getline(cin, name);
            cout << "Enter the new quantity: " << endl;
            cin >> qty;

            ItemToPurchase newItem;
            newItem.setName(name);
            newItem.setQuantity(qty);

            cart.modifyItem(newItem);
            cout << endl;
            printMenu(cart);
        }
        if (option != 'q') {
            cout << "Choose an option: " << endl;
            cin >> option;
        }
    }
    exit(1);
}

int main () {
    string name;
    string date;
    cout << "Enter customer's name: " << endl;
    getline(cin, name);

    cout << "Enter today's date: " << endl;
    getline(cin, date);
    cout << endl;

    cout << "Customer name: " << name << endl;
    cout << "Today's date: " << date << endl << endl;

    ShoppingCart cart(name, date);
    printMenu(cart);
}