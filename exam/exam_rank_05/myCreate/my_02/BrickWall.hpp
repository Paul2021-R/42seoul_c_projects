#ifndef BRICKWALL_HPP_
#define BRICKWALL_HPP_

#include <iostream>
#include <string>
#include "ASpell.hpp"

#define OUT std::cout
#define ENDL std::endl;

class BrickWall : public ATarget {
protected:

private :
BrickWall(const BrickWall& other);
BrickWall& operator=(const BrickWall& other);

public:
BrickWall();
~BrickWall();
BrickWall* clone();
};

#endif