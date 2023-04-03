#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}
Fwoosh::Fwoosh(const Fwoosh& other) : ASpell(other.getName(), getEffects()) {}
//   Fwoosh& operator=(const Fwoosh& other) {

// 	}
Fwoosh::~Fwoosh() {}
ASpell* Fwoosh::clone() const {
  Fwoosh* temp = new Fwoosh();
  return (temp);
}