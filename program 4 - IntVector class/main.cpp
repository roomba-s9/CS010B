#include <iostream>
#include "IntVector.h"
using namespace std;

int main () {
    IntVector *list = new IntVector();
    // I made the capacity() function public and tested it

    // cout << "List capacity: ";
    // cout << list->capacity() << endl;
    // list -> expand();
    // cout << list->capacity() << endl;
    // list -> expand();
    // cout << list->capacity() << endl;
    // list -> expand();
    // cout << list->capacity() << endl;
    // cout << "List size: ";
    // cout << list->size() << endl;
    // list->insert(0, 5);
    // cout << "List capacity: ";
    // cout << list->capacity() << endl;
    // cout << list->size() << endl;

    // testing push_back, insert, and erase functions
    // list->push_back(1);
    // list->push_back(2);
    // list->push_back(4);
    // list->push_back(5);
    // list->push_back(6);
    // list->insert(0, 0);
    // list->insert(3, 3);
    // list->erase(0);
    // list->erase(1);
    // list->erase(5);

    // testing reserve function
    // list->push_back(3);
    // list->reserve(50);
    // list->reserve(51);
    // list->reserve(50);
    // list->push_back(54);
    // list->reserve(60);

    // testing random functions
    // list->push_back(1);
    // list->push_back(2);
    // list->push_back(3);
    // list->push_back(4);
    // list->push_back(5);
    // list->push_back(6);
    // list->push_back(7);
    // list->push_back(8);

    // testing resize() function
    // list->push_back(1);
    // list->push_back(2);
    // list->push_back(3);
    // list->push_back(4);
    // list->push_back(5);
    // list->push_back(6);
    // list->resize(8, 3);

    //testing assign() function
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(5);
    list->push_back(6);
    list->assign(100, 3);

    // list->assign(100, 5);
    // list->resize(100, 5);

    // test harness for output
    cout << "List size: " << list->size() << endl;
    cout << "List capacity: " << list->capacity() << endl;
    cout << "List contents: ";
    for (unsigned i = 0; i < list->size(); ++i) {
        cout << list->at(i);
        if (i != list->size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    
    if (list->size() > 0) {
        cout << "List front: " << list->front() << endl;
        cout << "List back: " << list->back() << endl;
    }

    return -1;
}

void display() {
    
}