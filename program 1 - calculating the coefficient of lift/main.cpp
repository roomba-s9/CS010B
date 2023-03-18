#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main (int argc, char *argv[]) {
    // declaring variables
    string fileName = argv[1];
    double newFlightPath;
    string again;
    vector<double> flightPathAngle;
    vector<double> coefficientOfLift;

    readData(fileName, flightPathAngle, coefficientOfLift);
    if (!isOrdered(flightPathAngle)) {
        reorder(flightPathAngle, coefficientOfLift);
    }

    cout << "enter flight path" << endl;
    cin >> newFlightPath;
    cout << interpolation(newFlightPath, flightPathAngle, coefficientOfLift) << endl;
    cout << "Yes or No (Continue)" << endl;
    cin >> again;
    while (again == "Yes") {
        cout << "enter flight path" << endl;
        cin >> newFlightPath;
        cout << interpolation(newFlightPath, flightPathAngle, coefficientOfLift) << endl;
        cin >> again;
    }
    cout << "Thank you bye" << endl;
    
    return -1;
}

void readData(const string& fileName, vector<double>& f, vector<double>& c) {
    // declare temporary variables
    double temp1;
    double temp2;

    // opening file(s)
    ifstream inFS;
    inFS.open(fileName);
    if (!inFS.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }

    // inputing file data into variables
    while (inFS >> temp1 >> temp2) {
        f.push_back(temp1);
        c.push_back(temp2);
    }
    
    // close file
    inFS.close();
}

double interpolation(double n, const vector<double>& f, const vector<double>& c) {
    double num = -1.0;
    double fLow, fHigh, cLow, cHigh;

    for (unsigned i = 0; i < f.size(); ++i) {
        if (f.at(i) == n) {
            num = c.at(i);
        } else if (n > f.at(0) && n < f.at(f.size() - 1)) {
            // find: a < n < c such that |c-a| is minimal
            // a = low; c = high;
            // 1 2 4 5 6
            // given 3

            // f(n) = f(a) + ((n - a)/(c - a))(f(c) - f(a))
            // where f(x) = coefficient of lift
            // where x = flight angle
            int j = 0;
            while (f.at(j) < n) {
                j++;
            }
            fLow = f.at(j - 1);
            fHigh = f.at(j);
            cLow = c.at(j - 1);
            cHigh = c.at(j);

            num = cLow + ((n - fLow)/(fHigh - fLow)) * (cHigh - cLow);
        }
    }
    return num;
}

bool isOrdered(const vector<double>& f) {
    int size = f.size();
    for (int i = 0; i < size - 1; ++i) {
        if (!(f.at(i) <= f.at(i + 1))) {
                return false;
            }
    }
    return true;
}

void reorder(vector<double>& f, vector<double>& c) {
    int size = f.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (f.at(j) > f.at(j + 1)) {
                double temp1 = f.at(j);
                f.at(j) = f.at(j+1);
                f.at(j+1) = temp1;
                double temp2 = c.at(j);
                c.at(j) = c.at(j+1);
                c.at(j+1) = temp2;
            }
        }
    }
}
