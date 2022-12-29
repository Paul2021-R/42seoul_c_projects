#ifndef DUMMY_HPP_
#define DUMMY_HPP_

#include <iostream>
#include <string>
#include "ASpell.hpp"

#define OUT std::cout
#define ENDL std::endl;

class Dummy : public ATarget {
protected:

private :
Dummy(const Dummy& other);
Dummy& operator=(const Dummy& other);

public:
Dummy();
~Dummy();
Dummy* clone();
};

#endif