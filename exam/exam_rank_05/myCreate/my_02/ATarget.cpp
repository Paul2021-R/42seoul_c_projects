#include "ATarget.hpp"

ATarget::ATarget(const std::string& type): 
	type(type){}

ATarget::~ATarget() {
}
const std::string& ATarget::getType() const {
	return this->type;
}
ATarget* ATarget::clone() {
	ATarget* temp = new(ATarget)(getType());
	return temp;
}

void ATarget::getHitBySpell(const ASpell& spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}