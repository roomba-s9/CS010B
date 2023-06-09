#include "IntList.h"

bool IntList::bubbleUp() {
   return bubbleUp(head);
}

bool IntList::bubbleUp(IntNode *curr) {
   bool swapped = false;
   if (curr != nullptr && curr->next != nullptr) {

      swapped = bubbleUp(curr->next);

      if (curr->value > curr->next->value) {
         swap(curr->value, curr->next->value);
         swapped = true;
      }

   }
   return swapped;
}