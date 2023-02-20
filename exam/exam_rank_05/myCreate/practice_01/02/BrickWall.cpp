#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}
BrickWall::BrickWall(const BrickWall& other) : ATarget(other.getType()) {}
BrickWall::~BrickWall() {}
ATarget* BrickWall::clone() const {
  BrickWall* temp = new BrickWall();
  return (temp);
}