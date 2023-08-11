#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include "Character.h"

using namespace std;

class Warrior : public Character {
    
    public:
        Warrior(const string &name, double health, double attackStrength, string allegiance);
        const string & getAllegiance() const;
        void attack(Character &) override;
    private:
        string allegiance;

};

#endif