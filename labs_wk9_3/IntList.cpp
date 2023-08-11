#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &o, IntNode *temp) {
   if (temp == nullptr) {
      return o;
   }
   o << " " << temp->value;
   operator<<(o, temp->next);
   return o;
}

ostream & operator<<(ostream &o, const IntList &list) {
   if (list.head != nullptr) {
      o << list.head->value;
      operator<<(o, list.head->next);
      return o;
   }

   return o;
}

bool IntList::exists(IntNode *temp, int target) const {
   if (temp == nullptr) {
      return false;
   }
   else if (temp->value == target) {
      return true;
   }
   else {
      return exists(temp->next, target);
   }
}

bool IntList::exists(int target) const {
   return exists(head, target);
}