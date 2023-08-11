#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "Character.h"

using namespace std;

class Wizard : public Character {

    public: 
        Wizard(const string &name, double health, double attackStrength, int rank);
        const int & getRank() const;
        void attack(Character &) override;

    private:
        int rank;
};

#endif