#include "IntList.h"

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    while (head != nullptr) {
        IntNode *temp = head->next;
        delete head;
        head = temp;
    }
}

void IntList::push_front(int val) {
    IntNode *temp = new IntNode(val);
    temp->next = head;
    this->head = temp;
    if (tail == nullptr) {
        tail = head;
    }
}

void IntList::pop_front() {
    if (this->head == nullptr) {
        return;
    } else if (this->head == this->tail) {
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

//-----------------------------------------------------------

// copy constructor
IntList::IntList(const IntList& cpy) {
    // if list is empty
    if (cpy.head == nullptr) {
        head = nullptr;
        tail = nullptr;
    } else {
        // creates the head of the IntList, effectively making this the first value in the list
        head = new IntNode(cpy.head->value);

        // create a new IntNode that is the head of the IntList we are trying to copy
        IntNode *temp = cpy.head;

        // copy the remaining nodes from the old list
        while (temp->next != nullptr) {
            temp = temp->next;
            push_back(temp->value);
        }
    }
}

// assignment operator
IntList& IntList::operator=(const IntList& cpy) {
    if (this != &cpy) {
        // delete the old IntList
        clear();

        // copy the new list
        if (cpy.head != nullptr) {
            head = new IntNode(cpy.head->value);
            
            // creates two copies of the nodes
            // *currNew = IntList of current list
            // *currNew = IntList of cpy's list
            IntNode *currNew = head;
            IntNode *currOld = cpy.head->next;

            while (currOld != nullptr) {
                IntNode *newNode = new IntNode(currOld->value);
                currNew->next = newNode;
                currNew = currNew->next;
                currOld = currOld->next;
            }
            tail = currNew;
        }
    }
    return *this;
}

void IntList::push_back(int value) {
    // creates a new node that needs to be inserted to the back of the list
    IntNode* newNode = new IntNode(value);

    // if there is an empty list, the value that is put through push_back(int)
    // is the head and the tail of the new list
    if (head == nullptr) {
        head = newNode;
        tail = head;
    } else {
        // if there is not an empty list, make a new node to traverse through the 
        // list. it stops at the tail of the list.
        IntNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        // replaces (nullptr) with a new node, making that the new tail
        curr->next = newNode;
        tail = newNode;
    }   
}

void IntList::clear() {
    while (!empty()) {
        pop_front();
    }
}

void IntList::selection_sort() {
    // this function should do nothing if the list has 0 or 1 nodes
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    
    // creates a temporary node at the head of the list, solely for traversing through
    // the list once.
    IntNode *temp = head;
    while (temp != nullptr) {

        // traverses through the list and swaps every node that is bigger than the other
        IntNode *sort = temp->next;
        IntNode *min = temp;
        while (sort != nullptr) {
            if (sort->value < min->value) {
                min = sort;
            }
            sort = sort->next;
        }

        // swap the values of temp and min if min is smaller
        if (min != temp) {
            int t = temp->value;
            temp->value = min->value;
            min->value = t;
        }

        temp = temp->next;
    }
}

void IntList::insert_ordered(int value) {
    IntNode *temp = new IntNode(value);

    // if the list is empty, then just insert the IntNode
    if (head == nullptr) {
        head = temp;
        return;
    }

    // if the value is smaller than the first number, then
    // just insert the IntNode at the front of the linst
    if (value < head->value) {
        temp->next = head;
        head = temp;
        return;
    }

    // traverse the list to see where the IntNode belongs
    IntNode *before = head;
    IntNode *compare = head->next;

    while (compare != nullptr && compare->value < value) {
        compare = compare->next;
        before = before->next;
    }

    temp->next = before->next;
    before->next = temp;
}

void IntList::remove_duplicates() {
    // if the list size is 0 or 1, then do nothing
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // traverse through the list to compare values
    IntNode *current = head;
    while (current != nullptr) {
        // create another pointer to find if it is equal
        // to the first pointer
        IntNode *compare = current;
        while (compare->next != nullptr) {
            if (compare->next->value == current->value) {
                IntNode* duplicate = compare->next;
                compare->next = duplicate->next;
                delete duplicate;
            } else {
                compare = compare->next;
            }
            if (compare->next == nullptr) {
                tail = compare;
            }
        }
        current = current->next;
    }
}

ostream& operator<<(ostream &out, const IntList& rhs) {
    IntNode *temp = rhs.head;
    if (temp != nullptr) {
        out << temp->value;
        temp = temp->next;
    }
    while (temp != nullptr) {
        out << " " << temp->value;
        temp = temp->next;
    }

    return out;
}