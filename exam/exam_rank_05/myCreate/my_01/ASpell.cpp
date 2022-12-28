#include "ASpell.hpp"

ASpell::ASpell(std::string& name, std::string& effects) :
	name(name),
	effects(effects) {}
ASpell::~ASpell(){
	delete this;
}
const std::string& ASpell::getName() const{
	return this->name;
}
const std::string& ASpell::getEffects() const{
	return this->effects;
}
ASpell* ASpell::clone(){
	ASpell* temp = new(ASpell)(this->name, this->effects);
	return temp;
}

void ASpell::launch(const ATarget & target) {
	target.getHitBySpell(*this);
}