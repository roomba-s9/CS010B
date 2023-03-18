#include "IntList.h"
#include "SortedSet.h"

#include <iostream>
using namespace std;

int main() {
    IntList i1;
    IntList i2;
    IntList i3;
    IntList i4;

    i1.push_back(33);
    i1.push_back(22);
    i1.push_back(11);
    i1.push_back(44);
    i1.push_back(44);

    SortedSet s1;
    SortedSet s2;
    SortedSet s3;
    SortedSet s4;

    s1.push_back(1);
    s1.push_back(2);
    s1.push_back(3);
    s2.push_back(4);
    s2.push_back(5);
    s2.push_back(6);

/*

    cout << "---------------------\n";

    cout << "i1: " << i1 << endl;
    cout << "i2: " << i2 << endl;

    cout << "testing intlist copy constructor: i2 = i1" << endl;
    i2 = i1;
    cout << "i1: " << i1 << endl;
    cout << "i2: " << i2 << endl;

    cout << "---------------------\n";

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    cout << "testing sortedset copy constructor: s2 = s1" << endl;
    s2 = s1;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    
    cout << "---------------------\n";
 
    cout << "i1: " << i1 << endl;
    cout << "s3: " << s3 << endl;

    cout << "testing copy constructor of both sortedset and intlist: s3 = i1" << endl;
    s3 = i1;
    cout << "i1: " << i1 << endl;
    cout << "s3: " << s3 << endl;

    cout << "---------------------\n";

    cout << "i4: " << i4 << endl;
    cout << "s1: " << s1 << endl;

    cout << "testing copy constructor of both sortedset and intlist: i4 = s1" << endl;
    i4 = s1;
    cout << "i4: " << i4 << endl;
    cout << "s1: " << s1 << endl;

*/

/*
    cout << "s1: " << s1 << endl;
    cout << "testing if value 1 is in the list\n";
    if (s1.in(1) == 0) {
        cout << "false";
    } else {
        cout << "true";
    }
    cout << endl;

    cout << "testing if value 5 is in the list\n";
    if (s1.in(5) == 0) {
        cout << "false";
    } else {
        cout << "true";
    }
    cout << endl;
*/

/*  
    cout << "s2: " << s2 << endl;
    cout << "testing add() function" << endl;
    s2.add(1);
    s2.add(2);
    s2.add(3);
    s2.add(4);
    s2.add(5);
    s2.add(1);
    s2.add(2);
    s2.add(3);
    s2.add(4);
    s2.add(5);
    cout << "s2: " << s2 << endl;
*/

/*
    cout << "s2: " << s2 << endl;
    cout << "testing push_front() function" << endl;
    s2.push_front(1);
    s2.push_front(1);
    s2.push_front(1);
    s2.push_front(1);
    s2.push_front(5);
    cout << "s2: " << s2 << endl;
*/

/*
    cout << "s2: " << s2 << endl;
    cout << "testing push_back() function" << endl;
    s2.push_back(6);
    s2.push_back(1);
    s2.push_back(3);
    s2.push_back(1);
    s2.push_back(5);
    cout << "s2: " << s2 << endl;
*/

/*
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "Testing union operator: s3 = s1 | s2" << endl;
    s3 = s1 | s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "---------------------\n";

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "Testing union-assign operator: s1 = s1 | s2" << endl;
    s1 |= s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    s2.add(7);

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "Testing union-assign operator: s1 = s1 | s2" << endl;
    s1 |= s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
*/

/*
    cout << "------------------\n";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "Testing intersection-assign operator: s1 &= s2" << endl;
    s1 &= s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "------------------\n";

    s1.add(4);
    s1.add(5);
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    cout << "Testing intersection-assign operator: s1 &= s2" << endl;
    s1 &= s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
*/

   return 0;
}
