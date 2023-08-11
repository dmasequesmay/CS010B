#include <iostream>
#include <stdexcept>

#include "IntVector.h"

using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    
    _capacity = capacity;
    _size = capacity;

    if (capacity != 0) {
        _data = new int [_capacity];

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

//Private Helper Functions

void IntVector::expand() {

    if (_capacity == 0) {
        _capacity = 1;
        delete [] _data;
        _data = new int [_capacity];
    }
    else {
        int *temp = new int [_size];
        _capacity *= 2;

        for (unsigned int i = 0; i < _size; ++i) {
            temp[i] = _data[i];
            //cout << "TEMP[i]: " << temp[i] << endl;
        }

        delete [] _data;
        _data = new int [_capacity];

        for (unsigned int i = 0; i < _size; ++i) {
            _data[i] = temp[i];
            //cout << "TEMP[i]: " << _data[i] << endl;
        }

        delete [] temp;
        temp = nullptr;

    }
}

void IntVector::expand(unsigned amount) {

    _capacity += amount;
    int *temp = new int [_capacity];    

    for (unsigned int i = 0; i < _size; ++i) {
        temp[i] = _data[i];
    }

    delete [] _data;
    _data = new int [_capacity];

    for (unsigned int i = 0; i < _size; ++i) {
        _data[i] = temp[i];
    }

    delete [] temp;
    temp = nullptr;
}

//More Public Member Functions

void IntVector::insert(unsigned index, int value) {

    if (_size + 1 > _capacity) {
        expand();
    }

    if ( (index > _size) || (_capacity == 0) ) {
        throw out_of_range("IntVector::insert_range_check");
    }
    else if ( (index <= _size) && (_capacity >= _size + 1) ) {
        ++_size;
        for (unsigned int i = _size - 1; i > index; --i) {
        cout << "TEST: " << at(i) << " " << at(i - 1) << endl;
        at(i) = at(i - 1);
        }
        at(index) = value;
    }


}

void IntVector::erase(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }
    else {
        for (unsigned int i = index; i < _size - 1; ++i) {
            at(i) = at(i + 1);
        }
        --_size;
    }
}

void IntVector::push_back(int value) {
    if (_size + 1 > _capacity) {
        expand();
    }

    _data[_size] = value;

    ++_size;
}

void IntVector::pop_back() {
    --_size;
}

void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned size, int value) {
    if (size <= _size) {
        _size = size;
    } 
    else {
        //_size += size ;
        if (size > _capacity) {
            if (_capacity == 0) {
                expand(size);
            }
            // else if ( (_capacity * 2 < _capacity + size) || (_capacity == 0) ) {
            else if ( (_capacity * 2 > _capacity + (size - _capacity)) && (_capacity != 0) ){
                expand();
            }        
            else if (_capacity * 2 < _capacity + (size - _capacity)) {
                expand(size - _capacity);
            }
        }

        for (unsigned int i = _size  ; i < size; ++i) {
            _data[i] = value;

        }

        _size = size;
    }
}

void IntVector::reserve(unsigned n) {
    if ( (n > _capacity) && (n >= _size) ) {
        expand(n - _capacity);
    } 
    if (n < _capacity) {
        int *temp = new int [n];    ;

        for (unsigned int i = 0; i < n; ++i) {
            temp[i] = _data[i];
        }

        delete [] _data;
        _data = new int [n];

        for (unsigned int i = 0; i < n; ++i) {
            _data[i] = temp[i];
        }

        delete [] temp;
        temp = nullptr;
    }
}

void IntVector::assign(unsigned n, int value) {
    if (n > _capacity) {
        if (_capacity * 2 > n) {
            expand();
        }
        else {
            expand(n - _capacity);
        }
    }
    _size = n;
    for (unsigned int i = 0; i < _size; ++i) {
        at(i) = value;
    }
}

int & IntVector::at(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}

int & IntVector::front() {
    return _data[0];
}

int & IntVector::back() {
    return _data[_size - 1];
}
