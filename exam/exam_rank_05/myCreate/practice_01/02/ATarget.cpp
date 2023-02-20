#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::ATarget(const ATarget& other) { this->type_ = other.getType(); }
ATarget& ATarget::operator=(const ATarget& other) {
  this->type_ = other.getType();
  return *this;
}

ATarget::~ATarget() {}

ATarget::ATarget(const std::string& type) : type_(type) {}

const std::string& ATarget::getType(void) const { return this->type_; }

void ATarget::getHitBySpell(const ASpell& spell) const {
  std::cout << this->getType() << " has been " << spell.getEffects() << "!"
            << std::endl;
}