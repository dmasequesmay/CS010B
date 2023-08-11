#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

int main () {

    cout << "Enter a test number(1-5): ";
	int test;
	cin >> test;
	cout << endl;
   //tests constructor, destructor, push_front, pop_front, display
   if (test == 1) {
      cout << endl;
      cout << "Constructor called" << endl;
      SortedSet set1;
      set1.push_back(13);
      set1.push_back(5);
      cout << "set1: " << set1 << endl;
      SortedSet set2(set1);
      cout << "set2: " << set2 << endl;
      SortedSet list1;
      SortedSet set3(list1);
      cout << "set3: " << set3 << endl;
   }
   if (test == 1) {
      cout << "Destructor called" << endl;
   }

   //tests push_back
   if (test == 2) {
      cout << endl;
      cout << "list2 constructor called" << endl;
      SortedSet list2;
      cout << "pushback 10" << endl;
      list2.push_back(10);
      cout << "pushback 20" << endl;
      list2.push_back(20);
      cout << "pushback 30" << endl;
      list2.push_back(30);
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
   }
   if (test == 2) {
      cout << "list2 destructor called" << endl;
   }

   if (test==3) {
      cout << endl;
      cout << "list1 constructor called" << endl;
      SortedSet list1;
      cout << "pushback 10" << endl;
      list1.push_back(10);
      cout << "pushback 20" << endl;
      list1.push_back(20);
      cout << "pushback 30" << endl;
      list1.push_back(30);
      cout << "list1: " << list1 << endl;
      cout << "list2 constructor called" << endl;
      SortedSet list2;
      list2.push_back(30);
      cout << "pushback 30" << endl;
      list2.push_back(40);
      cout << "pushback 40" << endl;
      list2.push_back(50);
      cout << "pushback 50" << endl;
      cout << "list2: " << list2 << endl;
      SortedSet list3 = list1 | list2;
      cout << "list3: " << list3 << endl;
      SortedSet list4 = list1 & list2;
      cout << "list4: " << list4 << endl;
   }

return 0; 
}