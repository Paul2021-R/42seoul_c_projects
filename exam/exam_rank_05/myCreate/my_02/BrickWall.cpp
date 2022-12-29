#include "BrickWall.hpp"

BrickWall::BrickWall():
	ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall(){
}

BrickWall* BrickWall::clone(){
	BrickWall * temp = new(BrickWall)();
	return temp;
}