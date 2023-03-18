#ifndef SORTEDSET_H
#define SORTEDSET_H
#include "IntList.h"

using namespace std;

class SortedSet : public IntList {
 public:
   // CONSTRUCTORS AND DECONSTRUCTOR
   SortedSet();
   SortedSet(const SortedSet &);
   SortedSet(const IntList &);
   ~SortedSet();

   // ACCESSORS
   const bool in(int);
   const SortedSet operator|(SortedSet &) const;
   const SortedSet operator&(SortedSet &) const;

   // MUTATORS
   void add(int);
   void push_front(int);
   void push_back(int);
   void insert_ordered(int);
   SortedSet operator|=(SortedSet &);
   SortedSet operator&=(SortedSet &);

 private:
   
};

#endif