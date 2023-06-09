#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

// actual function
bool IntList::exists(int val) const {
   return exists(head, val);
}

// helper function
// returns true if "val" exists in IntList
bool IntList::exists(IntNode *temp, int val) const {
   // base case, if the value isn't found
   if (temp == nullptr) {
      return false;
   }
   if (temp->value == val) {
      return true;
   } else {
      // recursively calls the function again to determine if the value exists or not
      return exists(temp->next, val);
   }
}

// actual function
ostream & operator<<(ostream &out, const IntList &temp) {
   return operator<<(out, temp.head);
}

// helper function
ostream& operator<<(ostream &out, IntNode *temp) {
   // if the list is empty, output an empty string
   if (temp == nullptr) {
      return out;
   }
   // if the list is not empty, then output the value of the IntNode
   // into "out"
   out << temp->value;
   // if the value isn't the last one, add a space after the value
   if (temp->next != nullptr) {
      out << " ";
   }
   // recursively calls the function again to get the next value
   return operator<<(out, temp->next);
}