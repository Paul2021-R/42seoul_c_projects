#ifndef FWOOSH_HPP_
#define FWOOSH_HPP_

#include <iostream>
#include <string>
#include "ATarget.hpp"
#include "Aspell.hpp"

#define OUT std::cout
#define ENDL std::end;

class Fwoosh : public ASpell {
private:
Fwoosh(const Fwoosh& other);
Fwoosh& operator=(const Fwoosh& other);

public:
Fwoosh();
~Fwoosh();
const std::string& getName() const;
const std::string& getEffects() const;
Fwoosh* clone();
};

#endif