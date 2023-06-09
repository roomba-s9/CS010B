#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool rCopy(string, string);
void helperCopy(ifstream &, ofstream &);

int main (int argc, char *argv[]) {
    string inputFile = argv[1];
    string outputFile = argv[2];
    rCopy(inputFile, outputFile);
}

bool rCopy(const string inputFile, const string outputFile) {
    // create input stream
    ifstream inFile;
    inFile.open(inputFile);

    // verify if the file opened correctly
    if (!inFile.is_open()) {
        cout << "Error opening " << inputFile << endl;
        cout << "Copy not completed" << endl;
        return false;
    }

    // create output stream
    ofstream outFS;
    outFS.open(outputFile);

    if (!outFS.is_open()) {
        cout << "Error opening " << outputFile << endl;
        cout << "Copy not completed" << endl;
        return false;
    }

    helperCopy(inFile, outFS);

    inFile.close();
    outFS.close();

    return true;

}

void helperCopy(ifstream &inFile, ofstream &outFS) {
    // create a temporary variable to get a character
    // into ch
    char ch;
    inFile.get(ch);

    // base case: end of the file
    if (inFile.eof()) {
        return;
    }

    // the goal for this recursion is to output the 
    // characters into outputFile backwards
    helperCopy(inFile, outFS);
    outFS << ch;

}