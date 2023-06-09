#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(const string, const char);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(const string fileName, const char letter) {
   int count = 0;
   char ch;
   
   ifstream inFile(fileName);
   if (!inFile.is_open()) {
      cout << "Error opening " << fileName << endl;
      exit(1);
   }
   
   while (inFile.get(ch)) {
      if (ch == letter) {
         count++;
      }
   }

   return count;
}