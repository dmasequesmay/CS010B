#include <iostream>

#include "Elf.h"
#include "Character.h"

Elf::Elf(const string &name, double health, double attackStrength, string family)
    : Character(ELF, name, health, attackStrength), family(family)
{}

const string & Elf::getFamily() const {
    return family;
}

void Elf::attack(Character &opponent) {
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (family != opp.getFamily()) {
            opp.damage((health / MAX_HEALTH) * attackStrength);
            cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << (health / MAX_HEALTH) * attackStrength << " damage." << endl;
        }
        else {
            cout << "Elf " << this->name << " does not attack Elf " << opponent.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
        }
    }
    else {
        opponent.damage((health / MAX_HEALTH) * attackStrength);
        cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << (health / MAX_HEALTH) * attackStrength << " damage." << endl;
    }

}