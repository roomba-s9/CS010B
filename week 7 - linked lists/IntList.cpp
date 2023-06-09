#include "IntList.h"

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    while (head) {
        IntNode *t;
        t = head->next;
        delete head;
        head = t;
    }
    while (head != nullptr) {
        pop_front();
    }
}

void IntList::push_front(int val) {
    IntNode *temp = new IntNode(val);
    temp->next = this->head;
    this->head = temp;
    if (this->tail == nullptr) {
        this->tail = this->head;
    }
}

void IntList::pop_front() {
    if (this->head == nullptr) {
        return;
    } else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        IntNode *temp = head->next;
        delete head;
        head = temp;
    }
}

bool IntList::empty() const {
    if (this->head == nullptr) {
        return true;
    }
    return false;
}

const int& IntList::front() const {
    return head->value;
}

const int& IntList::back() const {
    return tail->value;
}

ostream & operator<<(ostream & out, const IntList & list) {
    IntNode *cur = list.head;
    while (cur) {
        out << " " << cur->value;
        cur = cur->next;
    }
    return out;
}