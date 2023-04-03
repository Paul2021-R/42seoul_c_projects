#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}
Fireball::Fireball(const Fireball& other)
    : ASpell(other.getName(), getEffects()) {}
//   Fireball& operator=(const Fireball& other) {

// 	}
Fireball::~Fireball() {}
ASpell* Fireball::clone() const {
  Fireball* temp = new Fireball();
  return (temp);
}