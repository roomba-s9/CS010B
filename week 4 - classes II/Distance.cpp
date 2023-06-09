#include <iostream>
#include <cmath>
#include "Distance.h"
using namespace std;

// CONSTRUCTORS
Distance::Distance() {
    this->_feet = 0;
    this->_inches = 0;
    init();
}

Distance::Distance(unsigned ft, double in) {
    this->_feet = fabs(ft);
    this->_inches = fabs(in);
    init();
}

Distance::Distance(double in) {
    this->_feet = 0;
    this->_inches = fabs(in);
    init();
}

// HELPER FUNCTIONS (ACCESSOR FUNCTIONS)
unsigned Distance::getFeet() const {
    return _feet;
}

double Distance::getInches() const {
    return _inches;
}

double Distance::distanceInInches() const {
    return _feet * 12 + _inches;
}

double Distance::distanceInFeet() const {
    return _inches / 12.0 + _feet;
}

double Distance::distanceInMeters() const {
    double totalInches;
    totalInches = _feet * 12 + _inches;
    return totalInches * 0.0254;
}

// HELPER FUNCTIONS (OPERATOR FUNCTIONS)
Distance Distance::operator+(const Distance &rhs) const {
    return Distance(this->_feet + rhs._feet, this->_inches + rhs._inches);
}

Distance Distance::operator-(const Distance &rhs) const {
    double totInchesOne = _feet * 12 + _inches;
    double totInchesTwo = rhs._feet * 12 + rhs._inches;
    if (totInchesOne > totInchesTwo) {
        return Distance(totInchesOne - totInchesTwo);
    } else {
        return Distance(totInchesTwo - totInchesOne);
    }
}

ostream& operator<<(ostream& out, const Distance& rhs) {
    out << rhs._feet << "\' " << rhs._inches << "\"";
    return out;
}

// HELPER FUNCTIONS (MUTATOR FUNCTIONS)
void Distance::init() {
    while (this->_inches >= 12) {
        this->_feet += 1;
        this->_inches -= 12;
    }
}