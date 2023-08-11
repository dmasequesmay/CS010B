#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

SortedSet::SortedSet() : IntList()
{}

SortedSet::SortedSet(const SortedSet &cpySet) : IntList(cpySet)
{}

SortedSet::SortedSet(const IntList &cpyList) : IntList(cpyList) 
{
    this->remove_duplicates();
    this->selection_sort();
}

SortedSet::~SortedSet() {
    this->~IntList();
}

bool SortedSet::in(int value) const {
    bool isIn = false;
    IntNode *currNode = head;
    while (currNode != nullptr) {
        if (currNode->value == value) {
            isIn = true;
        }
        currNode = currNode->next;
    }
    return isIn;
}

const SortedSet SortedSet::operator|(const SortedSet &rhs) {
    SortedSet result;
    if (this->head != nullptr) {
        IntNode *currNode = this->head;
        while (currNode->next != nullptr) {
            result.add(currNode->value);
            currNode = currNode ->next;
        }
        result.add(currNode->value);
        currNode = nullptr;
    }
    if (rhs.head != nullptr) {
        IntNode *currNode = rhs.head;
        while (currNode ->next != nullptr) {
            result.add(currNode->value);
            currNode = currNode ->next;
        }
        result.add(currNode->value);
        currNode = nullptr;
    }
    return result;
}

const SortedSet SortedSet::operator&(const SortedSet &rhs) {
    SortedSet result;
    int value;
    IntNode *currNode = this->head;    
    while (currNode != nullptr) {
        value = currNode->value;
        if (rhs.in(value)) {
            result.add(value);
        }
        currNode = currNode->next;
    }
    
    return result;
}

void SortedSet::add(int value) {
    if (!this->in(value)) {
        IntList::insert_ordered(value);
    }
}

void SortedSet::push_front(int value) {
    this->add(value);
}

void SortedSet::push_back(int value) {
    this->add(value);
}

void SortedSet::insert_ordered(int value) {
    this->add(value);
}

const SortedSet SortedSet::operator|=(const SortedSet &rhs) {
    *this = *this | rhs;
    return *this;
}

const SortedSet SortedSet::operator&=(const SortedSet &rhs) {
    *this = *this & rhs;
    return *this;
}