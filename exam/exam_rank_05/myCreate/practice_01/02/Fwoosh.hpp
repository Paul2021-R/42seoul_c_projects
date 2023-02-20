#ifndef Fwoosh_hpp
#define Fwoosh_hpp

#include "ASpell.hpp"

class Fwoosh : public ASpell {
 private:
 public:
  Fwoosh();
  Fwoosh(const Fwoosh& other);
  ~Fwoosh();
  ASpell* clone() const;
};

#endif