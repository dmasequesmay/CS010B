#include <iostream>

#include "Warrior.h"
#include "Character.h"

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) 
    : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance)
{}

const string & Warrior::getAllegiance() const {
    return allegiance;
}

void Warrior::attack(Character &opponent) {
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (allegiance != opp.getAllegiance()) {
            opp.damage((health / MAX_HEALTH) * attackStrength);
            cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << (health / MAX_HEALTH) * attackStrength << " damage." << endl;
        }
        else {
            cout << "Warrior " << name << " does not attack Warrior " << opponent.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
    }
    else {
        opponent.damage((health / MAX_HEALTH) * attackStrength);
        cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << (health / MAX_HEALTH) * attackStrength << " damage." << endl;
    }
}