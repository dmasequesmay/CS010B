#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s) {
   if (s.size() > 1) {
      char temp = s.front();
      s.front() = s.back();
      s.back() = temp;
      string flipped = s.substr(1, s.size() - 2);
      flipString(flipped);
      // cout << "Flipped: " << flipped << endl;
      // cout << "S: " << s << endl;
      s.replace(s.size() / 2 - (flipped.size() / 2), flipped.size(), flipped);
   }
}
   



