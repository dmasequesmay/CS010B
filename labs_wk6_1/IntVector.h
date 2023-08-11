#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>
#include <stdexcept>

using namespace std;

class IntVector {

    private:

        unsigned _size;
        unsigned _capacity;
        int *_data;

    public: 

       IntVector(unsigned capacity = 0, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int &at(unsigned index) const;
        const int &front() const;
        const int &back() const;

};

#endif