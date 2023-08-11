#include "IntList.h"
#include <iostream>

using namespace std;

bool IntList::bubbleUp() {
   return bubbleUp(head);
}

bool IntList::bubbleUp(IntNode *curr) {
   if (curr == nullptr) {
       return false;
   }
   else if (curr->next == nullptr) {
      return false;
   }
   else {
      bool flag = bubbleUp(curr->next);
      if (curr->value > curr->next->value) {
      int temp = curr->value;
      curr->value = curr->next->value;
      curr->next->value = temp;
      return true;
      }
      return flag;
   }
}


//programming 4,5,6 (functions and drawing linked lists and memory- stack and heap)
//lab 2 (file input and output)