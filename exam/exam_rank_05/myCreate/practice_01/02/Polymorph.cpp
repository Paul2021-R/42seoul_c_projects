#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}
Polymorph::Polymorph(const Polymorph& other)
    : ASpell(other.getName(), getEffects()) {}
//   Polymorph& operator=(const Polymorph& other) {

// 	}
Polymorph::~Polymorph() {}
ASpell* Polymorph::clone() const {
  Polymorph* temp = new Polymorph();
  return (temp);
}