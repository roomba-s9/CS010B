#include "SortedSet.h"

SortedSet::SortedSet():IntList() { }

SortedSet::SortedSet(const SortedSet &temp):IntList(temp) {
    remove_duplicates();
    selection_sort();
}

SortedSet::SortedSet(const IntList &temp):IntList(temp) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() { }

const bool SortedSet::in(int val) {
    if (empty()) {
        return false;
    }
    
    for (IntNode *curr = head; curr!= nullptr; curr = curr->next) {
        if (curr->value == val) {
            return true;
        } 
    }

    return false;

}

const SortedSet SortedSet::operator|(SortedSet &cpy) const {
    SortedSet list;

    for (IntNode *curr = head; curr != nullptr; curr = curr->next) {
        list.add(curr->value);
    }

    for (IntNode *curr = cpy.head; curr != nullptr; curr = curr->next) {
        list.add(curr->value);
    }

    return list;
}

const SortedSet SortedSet::operator&(SortedSet &cpy) const {
    SortedSet list;

    for (IntNode *curr = head; curr != nullptr; curr = curr->next) {
        for (IntNode *other = cpy.head; other != nullptr; other = other->next) {
            if (curr->value == other->value) {
                list.add(curr->value);
            }
        }
    }
    return list;
}

void SortedSet::add(int val) {
    IntNode *temp = new IntNode(val);
    // if the list is empty
    if (head == nullptr) {
        head = tail = temp;
    } else if (val < head->value) {
        // if new value is smallest in the list
        temp->next = head;
        head = temp;
    } else {
        // traverse through the list
        IntNode *before = head;
        IntNode *current = head->next;

        while (current != nullptr && current->value <= val) {
            current = current->next;
            before = before->next;
        }
        if (val != before->value) {
            temp->next = before->next;
            before->next = temp;
            // update tail value if the new node is at the end
            if (before == tail) {
                tail = temp;
            }
        }
    }
}

void SortedSet::push_front(int val) {
    add(val);
}

void SortedSet::push_back(int val) {
    add(val);
}

void SortedSet::insert_ordered(int val) {
    add(val);
}

SortedSet SortedSet::operator|=(SortedSet &cpy) {
    SortedSet list;

    for (IntNode *curr = head; curr != nullptr; curr = curr->next) {
        list.add(curr->value);
    }

    for (IntNode *curr = cpy.head; curr != nullptr; curr = curr->next) {
        list.add(curr->value);
    }

    *this = list;
    return *this;
}

SortedSet SortedSet::operator&=(SortedSet &cpy) {
    SortedSet list;

    for (IntNode *curr = head; curr != nullptr; curr = curr->next) {
        for (IntNode *other = cpy.head; other != nullptr; other = other->next) {
            if (curr->value == other->value) {
                list.add(curr->value);
            }
        }
    }
    
    *this = list;
    return *this;
}