#ifndef FIREBALL_HPP_
#define FIREBALL_HPP_

#include <iostream>
#include <string>
#include "ATarget.hpp"
#include "ASpell.hpp"

#define OUT std::cout
#define END std::endl;

class Fireball : public ASpell {

private:
Fireball(const Fireball& other);
Fireball& operator=(const Fireball& other);

public:
Fireball();
~Fireball();
Fireball* clone();
};

#endif