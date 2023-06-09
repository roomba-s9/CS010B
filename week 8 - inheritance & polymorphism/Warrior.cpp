#include <string>
#include <iostream>

#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string &name,
                double health,
                double attackStrength,
                const string &allegiance)
        : Character(type = WARRIOR, name, health, attackStrength),
          allegiance(allegiance) { }

void Warrior::attack(Character &opponent) {
    double dmg = 999;
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (opp.allegiance == allegiance) {
            // DON'T ATTACK
            cout << "Warrior " << getName() << " does not attack Warrior " << opponent.getName() << '.' << endl;
            cout << "They share an allegiance with " << allegiance << '.' << endl;
        } else {
            // ATTACK
            dmg = (health/MAX_HEALTH) * attackStrength;
            cout << "Warrior " << getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << dmg << " damage." << endl;
            opponent.damage(dmg);
        }
    } else {
        // ATTACK
        dmg = (health/MAX_HEALTH) * attackStrength;
        cout << "Warrior " << getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << dmg << " damage." << endl;
        opponent.damage(dmg);
    }
}