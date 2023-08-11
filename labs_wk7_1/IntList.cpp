#include <iostream>

#include "IntList.h"

using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    /*
    IntNode *currNode = head;
    IntNode *tempNode;
    while (currNode != nullptr) {
        tempNode = currNode;
        delete tempNode;
        currNode = currNode->next;
    }
    tempNode = nullptr;
    */
   while (head != nullptr) {
        pop_front();
   }
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
    /*
    } else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    */
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
        cout << currNode->value << " ";
        currNode = currNode->next;
    }

    cout << currNode->value;

return out;

}