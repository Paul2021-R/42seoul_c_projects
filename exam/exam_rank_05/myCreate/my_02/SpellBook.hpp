#ifndef SPELLBOOK_HPP_
#define SPELLBOOK_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "ASpell.hpp"


class SpellBook {
private:
std::vector<ASpell *> learned;

SpellBook(const SpellBook& other);
SpellBook& operator=(const SpellBook& other);

public:
SpellBook();
~SpellBook();
void learnSpell(ASpell * spell);
void forgetSpell(std::string const & name);
ASpell* createSpell(std::string const & name);
bool isEmpty();
};

#endif