#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const ASpell& other) {
  this->name_ = other.getName();
  this->effects_ = other.getEffects();
}

ASpell& ASpell::operator=(const ASpell& other) {
  this->name_ = other.getName();
  this->effects_ = other.getEffects();
  return *this;
}

ASpell::ASpell(const std::string& name, const std::string& effects)
    : name_(name), effects_(effects) {
  return;
}

ASpell::~ASpell() {}

const std::string& ASpell::getName() const { return this->name_; }
const std::string& ASpell::getEffects() const { return this->effects_; }

void ASpell::launch(const ATarget& target) const {
  target.getHitBySpell(*this);
  return;
}