#include <iostream>
#include "IntVector.h"
using namespace std;

int main () {
    IntVector *IntV = new IntVector();
    cout << IntV->size() << endl;
    cout << IntV->capacity() << endl;
    cout << IntV->empty() << endl;
    cout << "------------\n";
    IntVector *lol = new IntVector(10, 10);
    cout << lol->size() << endl;
    cout << lol->capacity() << endl;
    cout << lol->empty() << endl;
    cout << lol->at(0) << endl;
    cout << lol->front() << endl;
    cout << lol->back() << endl;

    return -1;
}

    // unsigned size() const;
    // unsigned capacity() const;
    // bool empty() const;
    // const int& at(unsigned index) const;
    // const int& front() const;
    // const int& back() const;