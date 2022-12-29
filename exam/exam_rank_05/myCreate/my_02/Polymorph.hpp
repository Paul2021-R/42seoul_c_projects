#ifndef POLYMORPH_HPP_
#define POLYMORPH_HPP_

#include <iostream>
#include <string>
#include "ATarget.hpp"
#include "ASpell.hpp"

#define OUT std::cout
#define END std::endl;

class Polymorph : public ASpell {

private:
Polymorph(const Polymorph& other);
Polymorph& operator=(const Polymorph& other);

public:
Polymorph();
~Polymorph();
Polymorph* clone();
};

#endif