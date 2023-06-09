#include <iostream>
#include <algorithm>

using namespace std;

// Rational Class declaration
class Rational {
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;

   private:
      int numerator;
      int denominator; 
      int gcd(int, int) const;   
};

// Implement Rational class member functions here

// Constructors
Rational::Rational(int num, int denom) {
   numerator = num;
   denominator = denom;
}

Rational::Rational(int num) {
   numerator = num;
   denominator = 1;
}

Rational::Rational() {
   numerator = 0;
   denominator = 1;
}

// Accessor Functions
// a = numerator
// b = denominator
// c = rat.numerator
// d = rat.denominator

int Rational::gcd(int x, int y) const {
   int temp;
   while (y != 0) {
      temp = y;
      y = x % y;
      x = temp;
   }
   return x;
}

Rational Rational::add(const Rational& rat) const{
   return Rational(numerator*rat.denominator + denominator*rat.numerator, denominator*rat.denominator);
}

Rational Rational::subtract(const Rational& rat) const{
   return Rational(numerator*rat.denominator - denominator*rat.numerator, denominator*rat.denominator);
}

Rational Rational::multiply(const Rational& rat) const{
   return Rational(numerator*rat.numerator, denominator*rat.denominator);
}

Rational Rational::divide(const Rational& rat) const{
   return Rational(numerator*rat.denominator, rat.numerator*denominator);
}

void Rational::display() const{
   cout << numerator << " / " << denominator;
}

void Rational::simplify() {
   int x = gcd(numerator, denominator);
   numerator /= x;
   denominator /= x;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {

   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}

Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}
