#include <string>
#include "Character.h"

using namespace std;

class Wizard : public Character {
 private:
    int rank;
 public:
    Wizard(const string &, double, double, int);
    void attack(Character &);
};