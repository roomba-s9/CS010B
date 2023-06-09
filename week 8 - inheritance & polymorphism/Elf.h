#include <string>
#include "Character.h"

using namespace std;

class Elf : public Character {
 protected:
    string familyName;
 public:
    Elf(const string &, double, double, const string &);
    void attack(Character &);
};