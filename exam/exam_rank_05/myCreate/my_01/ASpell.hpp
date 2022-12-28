#ifndef ASPELL_HPP_
#define ASPELL_HPP_

#include <iostream>
#include <string>
#include "ATarget.hpp"

#define OUT std::cout
#define ENDL std::end;

class ASpell {
protected:
std::string name;
std::string effects;

private:

public:
ASpell();
ASpell(const ASpell& other);
ASpell& operator=(const ASpell& other);
ASpell(std::string& name, std::string& effects);
virtual ~ASpell();
const std::string& getName() const;
const std::string& getEffects() const;
virtual ASpell* clone();
void launch(const ATarget & target);
};

#endif