#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];

   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);
   // Verify file opened correctly.
   if (!inFS.is_open()) {
      // Output error message and return 1 if file stream did not open correctly.
      cout << "Error opening " << inputFile << endl;
      exit(1);
   }
   
   // Read in integers from input file to vector.
   vector<int> inputVector;
   int myVal;
   char trash;

   while (!inFS.eof()) {
      inFS >> myVal;
      inputVector.push_back(myVal);
      inFS >> trash;
   }

/*
   //test and print inputVector
   for (unsigned int i = 0; i < inputVector.size(); +i) {
      cout << inputVector.at(i) << endl;
   }
*/

   // Close input stream.
   inFS.close();
   
   // Get integer average of all values read in.
   int sum = 0;
   int count = 0;
   int average;
   for (unsigned int i = 0; i < inputVector.size(); ++i) {
      sum += inputVector.at(i);
      count ++;
   }
   average = sum / count;
   
   // Convert each value within vector to be the difference between the original value and the average.
   
   for (unsigned int i = 0; i < inputVector.size(); ++i) {
      inputVector.at(i) = inputVector.at(i) - average;
   }

   // Create output stream and open/create output csv file.

   ofstream outFS;
   outFS.open(outputFile);

   // Verify file opened or was created correctly.
   if (!outFS.is_open()) {
      
   // Output error message and return 1 if file stream did not open correctly.
      cout << "Error opening " << outputFile << endl;
      exit (1);
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < inputVector.size() - 1; ++i) {
      outFS << inputVector.at(i) << ",";
   }
   outFS << inputVector.at(inputVector.size() - 1) << endl;
   // Close output stream.
   outFS.close();
   
   return 0;
}