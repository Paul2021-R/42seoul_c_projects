#ifndef Polymorph_hpp
#define Polymorph_hpp

#include "ASpell.hpp"

class Polymorph : public ASpell {
 private:
 public:
  Polymorph();
  Polymorph(const Polymorph& other);
  ~Polymorph();
  ASpell* clone() const;
};

#endif