#include <fstream>
#include <iostream>
#include <cstdlib> // needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum (string filename) {
   int sum = 0;
   int temp;
   
   ifstream file;
   file.open(filename);

   if (!file.is_open()) {
      cout << "Error opening " << filename << endl;
      exit(1);
   }

   while (file >> temp) {
      sum += temp;
   }

   return sum;

}