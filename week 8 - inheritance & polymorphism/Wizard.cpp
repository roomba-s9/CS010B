#include <string>
#include <iostream>

#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &name,
                double health,
                double attackStrength,
                int rank)
        : Character(type = WIZARD, name, health, attackStrength),
          rank(rank) { }

void Wizard::attack(Character &opponent) {
    double dmg = 999;
    if (opponent.getType() == 2) {
        // damage is affected by rank ratio
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        dmg = (1.0 * rank/opp.rank) * attackStrength;
    } else {
        // damage is only attack strength
        dmg = attackStrength;
    }
    cout << "Wizard " << getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    cout << opponent.getName() << " takes " << dmg << " damage." << endl;
    opponent.damage(dmg);
}