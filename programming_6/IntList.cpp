#include <iostream>

#include "IntList.h"

using namespace std;

IntList::IntList() 
: head(nullptr), tail(nullptr) 
{}

IntList::~IntList() {
   clear();
}   

void IntList::push_front(int value) {
    IntNode *temp = new IntNode(value);
    temp->next = this->head;
    head = temp;
    if (this->tail == nullptr) {
        this->tail = this->head;
    }
}

void IntList::pop_front() {
    if (empty()) {
        return;
    } else {
        IntNode* target = head;
        head = head->next;
        delete target;
        target = nullptr;
    }

    if (head == nullptr) {
        tail = nullptr;
    }
}

bool IntList::empty() const {
    if ( (head == nullptr) && (tail == nullptr) ) {
        return true;
    }
    else {
        return false;
    }
}

const int & IntList::front() const {
    return head->value;
}

const int & IntList::back() const {
    return tail->value;
}

ostream & operator<<(ostream &out, const IntList &list) {
    IntNode *currNode = list.head;
    if (list.empty()) {
        return out;
    }
    while (currNode->next != nullptr) {
        out << currNode->value << " ";
        currNode = currNode->next;
    }

    out << currNode->value;

return out;

}

IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    if (!cpy.empty()) {
        IntNode *currNode = cpy.head;
        while (currNode->next != nullptr) {
            push_back(currNode->value);
            currNode = currNode->next;
        }
        push_back(currNode->value);
        currNode = nullptr;
        
    }
}

IntList & IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        this->clear();
        if (!rhs.empty()) {
            IntNode *currNode = rhs.head;
            while (currNode->next != nullptr) {
                this->push_back(currNode->value);
                currNode = currNode->next;
            }
            this->push_back(currNode->value);
            currNode = nullptr;
        }
    }
    return *this;
}

void IntList::push_back(int value) {
    IntNode *temp = new IntNode(value);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } 
    else {
        tail->next = temp;
        tail = temp;
    }
}

void IntList::clear() {
    while (head != nullptr) {
        pop_front();
    }
   head = nullptr;
   tail = nullptr;
}

void IntList::selection_sort() {
    if (!empty()) {
        IntNode *i = head;
        IntNode *min = head;
        IntNode *target = head;
        int temp;
        while (i->next != nullptr) {
            //Find minimum
            while (target->next != nullptr) {
                target = target->next;
                if (target->value < min->value) {
                    min = target;
                }
            }
            //Swap variables
            temp = min->value;
            min->value = i->value;
            i->value = temp;
            //Reset 
            i = i->next;
            target = i;
            min = i;
        }
    }
}

void IntList::insert_ordered(int value) {
    if (empty()) {
        IntNode *target = new IntNode(value);
        head = target;
        tail = target;
    } 
    else if (head == tail) {
        if (value < head->value) {
            push_front(value);
        } 
        else {
            push_back(value);
        }
    }
    else if (value < head->value) {
        push_front(value);
    }
    else if (value > tail->value) {
        push_back(value);
    }
    else {
        IntNode *target = new IntNode(value);
        IntNode *prev = head;
        IntNode *curr = prev->next;
        
        while (curr != nullptr && curr->value < value) {
                prev = prev->next;
                curr = curr->next;  
        }
                prev->next = target;
                target->next = curr;
    }
}

void IntList::remove_duplicates() {
    if (!empty()) {
        IntNode *i = head;
        IntNode *prev = head;
        IntNode *curr = i->next;
        while ( (i != nullptr) && (i->next != nullptr) ) {
            while (curr != nullptr) {
                if (i->value == curr->value) {
                    if (curr->next == nullptr) {
                        prev->next = nullptr;
                        delete curr;
                        curr = nullptr;
                        tail = prev;
                    }
                    else {
                        prev->next = curr->next;
                        delete curr;
                        curr = prev->next;
                    }
                }
                else {
                    prev = prev->next;
                    curr = curr->next;
                }
            }
            i = i->next;
            if (i == nullptr) {
                prev = nullptr;
                curr = nullptr;
            }
            else {
                prev = i;
                curr = prev->next;
            }
        }
    }
}

IntNode * min(IntNode *) {
    return nullptr;
}

void copy(const IntList &) {}
