#include "IntVector.h"
#include <stdexcept>
using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    _data = nullptr;
    this->_capacity = capacity;
    this->_size = capacity;
    if (capacity != 0) {
        _data = new int[capacity];
    }
    if (_data != nullptr) {
        for (unsigned i = 0; i < capacity; ++i) {
            _data[i] = value;
        }
    }
}

unsigned IntVector::size() const {
    return this->_size;
}

unsigned IntVector::capacity() const {
    return this->_capacity;
}

bool IntVector::empty() const {
    if (this->_size == 0) {
        return true;
    }
    return false;
}

const int& IntVector::at(unsigned index) const {
    if (index >= this->_size) {
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

IntVector::~IntVector() {
    delete [] _data;
}

void IntVector::expand() {
    int prevCap = this->_capacity;
    if (this->_capacity == 0) {
        this->_capacity = 1;
    } else {
        this->_capacity *= 2;
    }
    int *temp = new int[this->_capacity];
    for (int i = 0; i < prevCap; ++i) {
        temp[i] = _data[i];
    }
    delete [] _data;
    _data = temp;
    temp = nullptr;
}

void IntVector::expand(unsigned amount) {
    int prevCap = this ->_capacity;
    this->_capacity = this->_capacity + amount;
    int *temp = new int[this->_capacity];
    for (int i = 0; i < prevCap; ++i) {
        temp[i] = _data[i];
    }
    delete [] _data;
    _data = temp;
    temp = nullptr;
}

void IntVector::insert(unsigned index, int value) {
    if (index > this->_size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    if (this->_size == this->_capacity) {
        expand();
        this->_size++;
    } else {
        this->_size++;
    }
    int *temp = new int[this->_capacity];

    for (unsigned i = 0; i < index; ++i) {
        temp[i] = this->_data[i];
    }
    temp[index] = value;
    for (unsigned i = index + 1; i < this->_size; ++i) {
        temp[i] = this->_data[i - 1];
    }
    delete [] _data;
    _data = temp;
    temp = nullptr;
}

void IntVector::erase(unsigned index) {
    if (index >= this->_size) {
        throw out_of_range("IntVector::erase_range_check");
    }
    int *temp = new int[this->_capacity];
    for (unsigned i = 0; i < index; ++i) {
        temp[i] = _data[i];
    }
    for (unsigned i = index; i < this->_size; ++i) {
        temp[i] = _data[i + 1];
    }
    this->_size--;
    delete [] _data;
    _data = temp;
    temp = nullptr;
}

void IntVector::push_back(int value) {
    if (this->_size == this->_capacity) {
        expand();
        this->_size++;
    } else {
        this->_size++;
    }
    int *temp = new int[_size];
    for (unsigned i = 0; i < _size; ++i) {
        temp[i] = _data[i];
    }
    temp[_size - 1] = value;
    delete [] _data;
    _data = temp;
    temp = nullptr;
}

void IntVector::pop_back() {
    this->_size--;
}

void IntVector::clear() {
    this->_size = 0;
}

void IntVector::resize(unsigned size, int value) {
    int prevSize = this->_size;
    if (size < this->_size) {
        this->_size = size;
    } else if (size > this->_size && size <= this->_capacity) {
        this->_size = size;
        int *temp = new int[this->_capacity];
        for (int i = 0; i < prevSize; ++i) {
            temp[i] = _data[i];
        }
        for (unsigned i = prevSize; i < size; ++i) {
            temp[i] = value;
        }
        delete [] _data;
        _data = temp;
        temp = nullptr;
    } else if (size > this->_capacity) {
        this->_size = size;
        if ( (this->_capacity) > (size - this->_capacity) ) {
            expand();
        } else {
            expand((size - this->_capacity));
        }
        int *temp = new int[this->_capacity];
        for (int i = 0; i < prevSize; ++i) {
            temp[i] = _data[i];
        }
        for (unsigned i = prevSize; i < size; ++i) {
            temp[i] = value;
        }
        delete [] _data;
        _data = temp;
        temp = nullptr;
    }
}

void IntVector::reserve(unsigned n) {
    if (this->_capacity < n) {
        this->_capacity = n;
    }
}

void IntVector::assign(unsigned n, int value) {
    if (n > this->_capacity) {
        if ( (this->_capacity) >= (n - this->_capacity) ) {
            expand();
        } else {
            expand((n - this->_capacity));
        }
    }
    this->_size = n;   
    delete [] _data;
    for (unsigned i = 0; i < this->_size; ++i) {
        _data[i] = value;
    }
}

int& IntVector::at(unsigned index) {
    if (index >= this->_size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

int& IntVector::front() {
    return _data[0];
}

int& IntVector::back() {
    return _data[this->_size - 1];
}


// unsigned _size;
// unsigned _capacity;
// int *_data;