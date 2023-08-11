#include <iostream>
#include <stdexcept>

#include "IntVector.h"

using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    
    _capacity = capacity;
    _size = capacity;

    if (capacity != 0) {
        _data = new int [_size];

        for (unsigned int i = 0; i < _capacity; ++i) {
            _data[i] = value;
        }
    }
    else {
        _data = nullptr;
    }
    
}

IntVector::~IntVector() {
    delete [] _data;
    _data = nullptr;
}

unsigned IntVector::size() const {
    return _size;
}

unsigned IntVector::capacity() const {
    return _capacity;
}

bool IntVector::empty() const {
    return (_size == 0);
}

const int & IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}

const int & IntVector::front() const {
    return _data[0];
}

const int & IntVector::back() const {
    return _data[_size - 1];
}
