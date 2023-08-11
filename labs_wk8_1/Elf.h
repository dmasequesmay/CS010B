#ifndef ELF_H
#define ELF_H

#include <iostream>
#include "Character.h"

using namespace std;

class Elf : public Character {

    public: 
        Elf(const string &name, double health, double attackStrength, string family);
        const string & getFamily() const;
        void attack(Character &) override;

    private:
        string family;
};

#endif