#include <iostream>

#include "Distance.h"

using namespace std;

void Distance::init() {
    if (_feet < 0) {
        _feet *= -1;
    }
    if (_inches < 0) {
        _inches *= -1;
    }
    while (_inches >= 12) {
        _feet++;
        _inches -= 12;
    }
}

Distance::Distance() {
    _feet = 0;
    _inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    _feet = ft;
    _inches = in;
    //cout << "TEST: " << _feet << " " << _inches << endl;
    while (_inches > 12) {
        init();
    }
    if ( (_feet < 0) || (_inches < 0) ) {
        init();
    }
}

Distance::Distance(double in) {
    _feet = 0;
    _inches = in;
    while (_inches > 12) {
        init();
    }
    if ( (_feet < 0) || (_inches < 0) ) {
        init();
    }
}

unsigned Distance::getFeet() const {
    return _feet;
}

double Distance::getInches() const {
    return _inches;
}

double Distance::distanceInInches() const {
    double result = _inches;
    result += (_feet * 12);
    return result;
}

double Distance::distanceInFeet() const {
    double result = _feet;
    result += (_inches / 12);
    return result;
}

double Distance::distanceInMeters() const {
    double result = distanceInInches();
    return result * 0.0254;
}

Distance Distance::operator+(const Distance &rhs) const {
    return Distance(_feet + rhs._feet, _inches + rhs._inches);
}

Distance Distance::operator-(const Distance &rhs) const {
    Distance result;
    double val1;
    double val2;
    val1 = distanceInInches();
    val2 = rhs.distanceInInches();
    if (val2 > val1) {
        result = Distance(rhs._feet - _feet, rhs._inches - _inches);
        //cout << "TEST: " << result._inches << endl;;
        if ((rhs._inches - _inches) < 0) {
        result._feet--;
        result._inches -= 12;
        result._inches *= -1;
        }
        return result;
    } 
    else {
        result = Distance(_feet - rhs._feet, _inches - rhs._inches);
        if (( _inches - rhs._inches) < 0) {
            result._feet--;
            result._inches -= 12;
            result._inches *= -1;
        }
        return result;
    }
}

ostream & operator<<(ostream &out, const Distance &rhs) {
    out << rhs._feet << "' " << rhs._inches << '"';
    return out;
}

