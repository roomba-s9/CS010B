#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   vector<int> list;
   int temp;
   int average;
   int sum;
   char dummy;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream inFile;
   inFile.open(inputFile);
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFile.is_open()) {
      cout << "Error opening " << inputFile << endl;
      return 1;
   }
   
   // Read in integers from input file to vector.
   while (inFile >> temp) {
      list.push_back(temp);
      inFile >> dummy;
   }
   
   // Close input stream.
   inFile.close();
   
   // Get integer average of all values read in.
   for (auto num : list) {
      sum += num;
   }

   average = sum / list.size();
   
   // Convert each value within vector to be the difference between the original value and the average.
   for (int &num : list) {
      num = num - average;
   }
   
   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()) {
      cout << "Error opening " << outputFile << endl;
   }
   
   // Write converted values into output csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < list.size(); ++i) {
      outFS << list.at(i);
      if (i != list.size() - 1) {
         outFS << ',';
      }
   }
   
   // Close output stream.
   outFS.close();
   
   return 0;
}