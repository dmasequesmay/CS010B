#include <iostream>
#include <stdexcept>

using namespace std;

#include "IntVector.h"


int main () {

 /*

    cout << "Executing Test Harness..." << endl << endl;

    cout << "TEST HARNESS 1: Default Constructor" << endl;

    cout << "SIZE: 0" << endl;
    cout << "CAPACITY: 0" << endl;
    cout << "EMPTY: true" << endl;
    
    cout << endl;

    IntVector vector;

    cout << "SIZE: " << vector.size() << endl;
    cout << "CAPACITY: " << vector.capacity() << endl;
    if (vector.empty()) {
        cout << "EMPTY: true" << endl;
    }
    else {
        cout << "EMPTY: false" << endl;
    }   

    vector.insert(1,100);

 */

/*
    cout << "TEST HARNESS 2: Size and Capacity" << endl;

    cout << "SIZE: 100" << endl;
    cout << "CAPACITY: 100" << endl;
    cout << "EMPTY: false" << endl;

    cout << endl;

    IntVector vector(100);

    cout << "SIZE: " << vector.size() << endl;
    cout << "CAPACITY: " << vector.capacity() << endl;
    if (vector.empty()) {
        cout << "EMPTY: true" << endl;
    }
    else {
        cout << "EMPTY: false" << endl;
    }

*/

/*

    cout << "TEST HARNESS 3: At, Front, Back" << endl;

    cout << "VAL AT INDEX 3: 28" << endl;
    cout << "FRONT: 28" << endl;
    cout << "BACK: 28" << endl;

    cout << endl;

    IntVector vector(4,28);
    
    cout << "VAL AT INDEX 3: " << vector.at(10) << endl;
    cout << "FRONT: " << vector.front() << endl;
    cout << "BACK: " << vector.back() << endl;

*/

// /*

cout << "TEST HARNESS 4:" << endl;

IntVector vector(10,5);

cout << "BEFORE: " << endl;

cout << "SIZE: " << vector.size() << endl;
cout << "CAPACITY: " << vector.capacity() << endl;

for (unsigned int i = 0; i < vector.size(); ++i) {
    cout << vector.at(i) << " ";
}

cout << endl;

vector.resize(15,898);

cout << "AFTER:" << endl;

cout << "SIZE: " << vector.size() << endl;
cout << "CAPACITY: " << vector.capacity() << endl;

for (unsigned int i = 0; i < vector.size(); ++i) {
    cout << vector.at(i) << " ";
}

cout << endl;

// */


/*
cout << "Starting final test harness:" << endl;

IntVector vector;
int userInput;

cout << "SIZE: " << vector.size() << endl;
cout << "CAPACITY: " << vector.capacity() << endl;
if (vector.empty()) {
    cout << "EMPTY: true" << endl;
}
else {
    cout << "EMPTY: false" << endl;
}   

cout << "Resize vector to 5 elements" << endl;

vector.resize(5);

cout << "SIZE: " << vector.size() << endl;
cout << "CAPACITY: " << vector.capacity() << endl;

for (unsigned int i = 0; i < vector.size(); ++i) {
    cout << "Enter input value: ";
    cin >> userInput;
    cout << endl;
    vector.at(i) = userInput;
}

for (unsigned int i = 0; i < vector.size(); ++i) {
    cout << vector.at(i) << " ";
}

cout << endl;

cout << "Insert value 17 at index 3" << endl;

vector.insert(3, 17);

for (unsigned int i = 0; i < vector.size(); ++i) {
    cout << vector.at(i) << " ";
}

cout << endl;

cout << "Erase value at index 5" << endl;

vector.erase(5);

for (unsigned int i = 0; i < vector.size(); ++i) {
    cout << vector.at(i) << " ";
}

cout << endl;

cout << "Output first element" << endl;

cout << vector.front() << endl;

cout << "Output last element" << endl;

cout << vector.back() << endl;

cout << "Pushback value 32" << endl;

cout << "Before: ";

for (unsigned int i = 0; i < vector.size(); ++i) {
    cout << vector.at(i) << " ";
}

cout << endl;

vector.push_back(32);

cout << "After: ";

for (unsigned int i = 0; i < vector.size(); ++i) {
    cout << vector.at(i) << " ";
}

cout << endl;

cout << "Pop_back to remove last element" << endl;

vector.pop_back();

for (unsigned int i = 0; i < vector.size(); ++i) {
    cout << vector.at(i) << " ";
}

cout << endl;

cout << "Assign 7 elements with value 28" << endl;

vector.assign(7, 28);

for (unsigned int i = 0; i < vector.size(); ++i) {
    cout << vector.at(i) << " ";
}

cout << endl;

cout << "Reserve to make size remain 7 and capacity 30" << endl;

vector.reserve(30);

cout << "SIZE: " << vector.size() << endl;
cout << "CAPACITY: " << vector.capacity() << endl;

cout << "Clear vector" << endl;

vector.clear();

cout << "SIZE: " << vector.size() << endl;
cout << "CAPACITY: " << vector.capacity() << endl;
if (vector.empty()) {
    cout << "EMPTY: true" << endl;
}
else {
    cout << "EMPTY: false" << endl;
}   

cout << "Finished testing harness." << endl;


*/

return 0;

}
