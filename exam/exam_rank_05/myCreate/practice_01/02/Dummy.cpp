#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}
Dummy::Dummy(const Dummy& other) : ATarget(other.getType()) {}
Dummy::~Dummy() {}
ATarget* Dummy::clone() const {
  Dummy* temp = new Dummy();
  return (temp);
}