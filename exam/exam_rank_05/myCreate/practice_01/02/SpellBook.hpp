#ifndef SpellBook_hpp
#define SpellBook_hpp

#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "Fireball.hpp"
#include "Fwoosh.hpp"
#include "Polymorph.hpp"

class SpellBook {
 private:
  std::map<std::string, ASpell*> book;

  SpellBook(const SpellBook& other);
  SpellBook& operator=(const SpellBook& other);

 public:
  SpellBook();
  ~SpellBook();

  void learnSpell(ASpell* spell);
  void forgetSpell(const std::string& spell_name);
  ASpell* createSpell(const std::string& spell_name);
};

#endif