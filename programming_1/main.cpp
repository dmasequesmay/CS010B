#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readData(const string &inputFile, vector<double> &flightAngles, vector<double> &liftCoeffs);
double interpolation(double userInput, const vector<double> &flightAngles, const vector<double> &liftCoeffs);
bool isOrdered(const vector<double> &flightAngles);
void reorder(vector<double> &flightAngles, vector<double> &liftCoeffs);

int main(int argc, char *argv[]) {

    string inputFile;
    inputFile = argv[1];

    vector<double> flightAngles;
    vector<double> liftCoeffs;

    readData(inputFile, flightAngles, liftCoeffs);

    if (isOrdered(flightAngles) == false) {
        reorder(flightAngles, liftCoeffs);
    }

    double angleInterpolation;
    double userInput;

    cout << "Enter requested flight-path angle: ";
    cin >> userInput;
    cout << endl;

    if ( (userInput >= flightAngles.at(0)) && (userInput <= flightAngles.at(flightAngles.size() - 1)) ) {
        angleInterpolation = interpolation(userInput, flightAngles, liftCoeffs); 
    }


    cout << "Coefficient of lift: " << angleInterpolation << endl;

    string userVal;

    cout << "Enter another flight-path angle? ";
    cin >> userVal;
    cout << endl;

    while (userVal == "Yes") {
        cout << "Enter requested flight-path angle: ";
        cin >> userInput;
        cout << endl;

        if ( (userInput >= flightAngles.at(0)) && (userInput <= flightAngles.at(flightAngles.size() - 1)) ) {
            angleInterpolation = interpolation(userInput, flightAngles, liftCoeffs); 
        }


        cout << "Coefficient of lift: " << angleInterpolation << endl;

        cout << "Enter another flight-path angle? ";
        cin >> userVal;
        cout << endl;

    }

    return 0;
}

void readData(const string &inputFile, vector<double> &flightAngles, vector<double> &liftCoeffs) {

    ifstream inFS;
    double tempAngle;
    double tempCoeff;

    inFS.open(inputFile);

    if (!inFS.is_open()) {
        cout << "Error opening " << inputFile << endl;
        exit(1);
    }

    while (inFS >> tempAngle) {
        flightAngles.push_back(tempAngle);
        inFS >> tempCoeff;
        liftCoeffs.push_back(tempCoeff);
    }
/*
    for (unsigned int i = 0; i < flightAngles.size(); ++i) {
        cout << flightAngles.at(i) << " " << liftCoeffs.at(i) << endl;
    }
*/
    
}

double interpolation(double userInput, const vector<double> &flightAngles, const vector<double> &liftCoeffs) {

    bool InputExists = false;
    double coeffInterpolation;
    double coeff_b;

    for (unsigned int i = 0; i < flightAngles.size(); ++i) {
        if (userInput == flightAngles.at(i)) {
            coeffInterpolation = liftCoeffs.at(i);
            InputExists = true;
        }
    }

    if (InputExists) {
        coeff_b = coeffInterpolation;
    }
    else {
        double a;
        double b;
        double c;
        double coeff_a;
        double coeff_c;
        bool isGreater = false;

        b = userInput;

        for (unsigned int i = 0; i < flightAngles.size(); ++i) {
            if ((isGreater == false) && (flightAngles.at(i) > b)) {
                c = flightAngles.at(i);
                a = flightAngles.at(i - 1);
                coeff_a = liftCoeffs.at(i - 1);
                coeff_c = liftCoeffs.at(i);
                isGreater = true;
            }
        }

        coeff_b = coeff_a + ( (b - a) / (c - a) ) * (coeff_c - coeff_a);
    }

    return coeff_b;
}

bool isOrdered(const vector<double> &flightAngles) {
    bool isItOrdered = true;

    if ( (flightAngles.size() == 0) || (flightAngles.size() == 1) )  {
        return true;
    }

    for (unsigned int i = 0; i < flightAngles.size() - 1; ++i) {
        if (flightAngles.at(i) > flightAngles.at(i + 1)) {
            isItOrdered = false;
        }
    }

    return isItOrdered;
}

void reorder(vector<double> &flightAngles, vector<double> &liftCoeffs) {
    int indexSmallest;
    double tempAngles;
    double tempCoeffs;

    for (unsigned int i = 0; i < flightAngles.size(); ++i) {
        indexSmallest = i;
        for (unsigned int j = i + 1; j < flightAngles.size(); ++j) {
            if (flightAngles.at(j) < flightAngles.at(indexSmallest)) {
                indexSmallest = j;
            }
        }
        tempAngles = flightAngles.at(i);
        flightAngles.at(i) = flightAngles.at(indexSmallest);
        flightAngles.at(indexSmallest) = tempAngles;

        tempCoeffs = liftCoeffs.at(i);
        liftCoeffs.at(i) = liftCoeffs.at(indexSmallest);
        liftCoeffs.at(indexSmallest) = tempCoeffs;
    }
/*
     for (unsigned int i = 0; i < flightAngles.size(); ++i) {
        cout << flightAngles.at(i) << " " << liftCoeffs.at(i) << endl;
    }
*/
}