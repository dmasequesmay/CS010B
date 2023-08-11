#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <iostream>
#include "IntList.h"

using namespace std;

class SortedSet : public IntList {
    
    public: 

        SortedSet();
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();
        bool in(int value) const;
        const SortedSet operator|(const SortedSet &);
        const SortedSet operator&(const SortedSet &);
        void add(int value);
        void push_front(int value);
        void push_back(int value);
        void insert_ordered(int value);
        const SortedSet operator|=(const SortedSet &);
        const SortedSet operator&=(const SortedSet &);
};

#endif