#ifndef ATARGET_HPP_
#define ATARGET_HPP_

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
std::string type;

private:
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