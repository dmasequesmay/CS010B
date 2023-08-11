#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

int main() {
/* 	int seed;
	cout << "Enter seed value: ";
	cin >> seed;
	cout << endl;
	
	srand(seed);

	vector<Character *> adventurers;
	adventurers.push_back(new Warrior("Arthur", 100, 5, "King George"));
	adventurers.push_back(new Warrior("Jane", 100, 6, "King George"));
	adventurers.push_back(new Warrior("Bob", 100, 4, "Queen Emily"));
	adventurers.push_back(new Elf("Raegron", 100, 4, "Sylvarian"));
	adventurers.push_back(new Elf("Cereasstar", 100, 3, "Sylvarian"));
	adventurers.push_back(new Elf("Melimion", 100, 4, "Valinorian"));
	adventurers.push_back(new Wizard("Merlin", 100, 5, 10));
	adventurers.push_back(new Wizard("Adali", 100, 5, 8));
	adventurers.push_back(new Wizard("Vrydore", 100, 4, 6));

	unsigned numAttacks = 10 + rand() % 11;
	unsigned attacker, defender;
	for (unsigned i = 0; i < numAttacks; ++i) {
		attacker = rand() % adventurers.size();
		do {
			defender = rand() % adventurers.size();
		} while (defender == attacker);
		
		adventurers.at(attacker)->attack(*adventurers.at(defender));
		cout << endl;
	}
	cout << "-----Health Remaining-----" << endl;
	for (unsigned i = 0; i < adventurers.size(); ++i) {
		cout << adventurers.at(i)->getName() << ": " 
			<< adventurers.at(i)->getHealth() << endl;
	} */

	Warrior w1("Arthur", 100, 5, "King George");
    Warrior w2("Jane", 100, 6, "King George");
    Warrior w3("Bob", 100, 4, "Queen Emily");
    Elf e1("Raegron", 100, 4, "Sylvarian");
    Elf e2("Cereasstar", 100, 3, "Sylvarian");
    Elf e3("Melimion", 100, 4, "Valinorian");
    Wizard wz1("Merlin", 100, 5, 10);
    Wizard wz2("Adali", 100, 5, 8);
    Wizard wz3("Vrydore", 100, 4, 6);
    e1.attack(w1);
    cout << endl;
    e1.attack(e2);
    cout << endl;
    w2.attack(w1);
    cout << endl;
    w3.attack(w1);
    cout << endl;
    wz1.attack(wz2);
    cout << endl;
    wz1.attack(wz3);
    cout << endl;


	/* Warrior w1("Arthur", 100, 5, "Kingdom");
	cout << w1.getType() << endl;
	cout << w1.getName() << endl;
	cout << w1.getHealth() << endl;
	w1.damage(50);
	cout << w1.getHealth() << endl;
	if (w1.isAlive()) {
		cout << "Is Alive" << endl;
	}
	else {
		cout << "Is Not Alive" << endl;
	} */


	return 0;
}