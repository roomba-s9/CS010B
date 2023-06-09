#include "IntVector.h"
#include <stdexcept>
using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    this->_capacity = capacity;
    this->_size = capacity;
    _data = new int[capacity];
    if (capacity > 0) {
        for (unsigned i = 0; i < capacity; ++i) {
            _data[i] = value;
        }
    }
}

IntVector::~IntVector() {
    delete _data;
}

unsigned IntVector::size() const {
    return this->_size;
}

unsigned IntVector::capacity() const {
    return this-> _capacity;
}

bool IntVector::empty() const {
    if (this->_size == 0) {
        return true;
    }
    return false;
}

const int& IntVector::at(unsigned index) const {\
    if (index >= _capacity) {
        throw out_of_range("IntVector::at_range_check");
    }
    
    return _data[index];
}

const int& IntVector::front() const {
    return _data[0];
}

const int& IntVector::back() const {
    return _data[_size - 1];
}