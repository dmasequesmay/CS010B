#include<iostream>
#include<fstream>

using namespace std;

bool rCopy(const string &inputFile, const string &outputFile);
void rCopyHelper(ifstream &inFS, ofstream &outFS);

int main (int argc, char *argv[]) {

    if (argc != 3) {
        exit(1);
    }

    if (rCopy(argv[1], argv[2])) {
        cout << "Copy completed" << endl;
    }
    else {
        cout << "Copy not completed" << endl;
    }
    

    return 0;

}

bool rCopy(const string &inputFile, const string &outputFile) {

    ifstream inFS;
    inFS.open(inputFile);

    if (!inFS.is_open()) {
        cout << "Error opening " << inputFile << endl;
        return false;
    }
    else {
        ofstream outFS;
        outFS.open(outputFile);

        if (!outFS.is_open()) {
            cout << "Error opening " << outputFile << endl;
            return false;
        }
        else {
            rCopyHelper(inFS, outFS);
            inFS.close();
            outFS.close();
        }

    }
    

return true;

}

void rCopyHelper(ifstream &inFS, ofstream &outFS) {
    
    char myChar;
    if (!inFS.get(myChar)) {
        return;
    }
    else {
        rCopyHelper(inFS, outFS);
        outFS << myChar;
    }

}

