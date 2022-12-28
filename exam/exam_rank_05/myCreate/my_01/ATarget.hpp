#ifndef ATARGET_HPP_
#define ATARGET_HPP_

#include <iostream>
#include <string>
#include "ASpell.hpp"

#define OUT std::cout
#define ENDL std::endl;

class ATarget {
protected:
std::string type;

ATarget();
ATarget(const ATarget& other);
ATarget& operator=(const ATarget& other);

public:
ATarget(const std::string& type);
~ATarget();
const std::string& getType() const;
virtual ATarget* clone();
void getHitBySpell(const ASpell& spell) const;
};

#endif