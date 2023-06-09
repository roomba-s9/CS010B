#include <string>
#include <iostream>

#include "Elf.h"

using namespace std;

Elf::Elf(const string &name, 
         double health, 
         double attackStrength, 
         const string &familyName) 
    : Character(type = ELF, name, health, attackStrength), 
      familyName(familyName) { }

void Elf::attack(Character &opponent) {
    double dmg = 999;
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (opp.familyName == familyName) {
            // DON'T ATTACK
            cout << "Elf " << getName() << " does not attack Elf " << opponent.getName() << '.' << endl;
            cout << "They are both members of the " << familyName << " family." << endl;
        } else {
            // ATTACK
            dmg = ((health/MAX_HEALTH) * attackStrength);
            cout << "Elf " << getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << dmg << " damage." << endl;
            opponent.damage(dmg);
        }
    } else {
        // ATTACK
        dmg = ((health/MAX_HEALTH) * attackStrength);
        cout << "Elf " << getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << dmg << " damage." << endl;
        opponent.damage(dmg);
    }
}