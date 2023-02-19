#ifndef FWOOSH_HPP_
#define FWOOSH_HPP_

#include <iostream>
#include <string>
#include "ATarget.hpp"
#include "ASpell.hpp"

#define OUT std::cout
#define END std::endl;

class Fwoosh : public ASpell {

private:
Fwoosh(const Fwoosh& other);
Fwoosh& operator=(const Fwoosh& other);

public:
Fwoosh();
~Fwoosh();
Fwoosh* clone();
};

#endif