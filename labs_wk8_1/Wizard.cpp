#include <iostream>

#include "Wizard.h"
#include "Character.h"

Wizard::Wizard(const string &name, double health, double attackStrength, int rank)
    : Character(WIZARD, name, health, attackStrength), rank(rank)
{}
const int & Wizard::getRank() const {
    return rank;
}
void Wizard::attack(Character &opponent) {
    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        opponent.damage(attackStrength * ((rank * 1.0) / opp.getRank()));
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << attackStrength * ((rank * 1.0) / opp.getRank()) << " damage." << endl;
    }
    else {
        opponent.damage(attackStrength);
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << attackStrength << " damage." << endl;
    }
}