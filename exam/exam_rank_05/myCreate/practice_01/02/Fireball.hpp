#ifndef Fireball_hpp
#define Fireball_hpp

#include "ASpell.hpp"

class Fireball : public ASpell {
 private:
 public:
  Fireball();
  Fireball(const Fireball& other);
  ~Fireball();
  ASpell* clone() const;
};

#endif